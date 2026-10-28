"""
코드 구조
- ActionServer 클래스를 import 하여 액션 서버 생성
- excute_callback 메서드에서 Goal을 처리
- goal_handle.succeed()를 호출하여 성공알림
- Result 객체에 결과를 담아 반환

피드백 기능 추가
- excute_callback 내에서 주기적으로 feedback을 발행
- goal_handle.oublish_feedback()으로 중간 상태 전송
- 클라이언트에서 --feedback 옵션으로 수신 가능
"""

import time
import rclpy as rp
from rclpy.action                   import ActionServer
from rclpy.executors                import MultiThreadedExecutor
from rclpy.node                     import Node

from turtlesim.msg                  import Pose
from geometry_msgs.msg              import Twist
from my_first_package_msgs.action   import DistTurtle
from my_first_package.my_subscriber import TurtlesimSubscriber

import math
import time

class TurtleSub_Action(TurtlesimSubscriber):
    """
    - 기존 TurtlesimSubscriber를 상속하여(inheritance)하여 확장
    - 생성자에서 ac_server(액션 서버 인스턴스)를 전달 받음
    - callback 메서드를 오버라이드(override) 하여 동작 변경
    - turtlesim의 pose 토픽을 구독하여 현재 위치를 액션 서버에 전달
    - 이렇게 하면 액션 서버가 직접 구독하지 않아도 실시간 위치 확인 가능
    """
    def __init__(self, ac_server):
        super().__init__()
        self.ac_server = ac_server

    def callback(self, msg):
        self.ac_server.current_pose = msg

class DistTurtleServer(Node):
    def __init__(self):
        """
        DistTurtleServer 초기화
        - Node를 상속하여 "dist_turtle_action_server" 이름의 노드 생성
        - total_dist: 누적 이동 거리를 추적하는 변수
        - is_first_time: 첫번째 콜백 호출 여부를 판단하는 플래그
        - current_pose / previous_pose: 현재/이전 위치 저장용 Pose 객체
        - publisher: /turtle1/cmd_vel 토픽으로 이동 명령을 발행
        - action_server: DistTurtle 타입의 "dist_turtle" 액션 서버 생성, execute_callback 콜백으로 등록
        """
        super().__init__("dist_turtle_action_server")
        self.total_dist     = 0
        self.is_first_time  = True
        self.current_pose   = Pose()
        self.previous_pose  = Pose()
        self.publisher      = self.create_publisher(Twist, "/turtle1/cmd_vel", 10)
        self._action_server = ActionServer(self, DistTurtle, "dist_turtle", self.execute_callback)

    def calc_diff_pose(self):
        """
        거리 계산 메서드
        - 두점 사이의 유클리드 거리(Euclidean distance)를 계산
        - 공식: sqrt((x2 - x2)^2 + (y2 - y1)^2)
        - 첫 호출시에는 previous_pose를 current_pose로 초기화하여 초기 거리 = 0
        - 이후 매 호출 마다 이전 위치와 현재 위치의 차이를 계산
        - 계산 후 previous_pose를 current_pose로 업데이트
        """
        if self.is_first_time:
            self.previous_pose.x = self.current_pose.x
            self.previous_pose.y = self.current_pose.y
            self.is_first_time = False

        diff_dist = math.sqrt((self.current_pose.x - self.previous_pose.x) ** 2 + 
                              (self.current_pose.y - self.previous_pose.y) ** 2)

        self.previous_pose = self.current_pose

        return diff_dist

    def execute_callback(self, goal_handle):
        """
        execute_callback 초기 설정
        - goal_handle 에서 요청된 Goal 데이터 추출
        - feedback_msg: 피드백 메시지 객체 생성
        - msg(Twist): 거북이에게 보낼 이동 명령 생성
        - Goal의 linear_x, angular_z 값을 Twist 메시지에 설정
        - 이 값들은 while 루프에서 반복적으로 발행됨

        execute_callback 이동 루프 동작
        - 무한 루프(while True) 안에서 거북이를 계속 이동시킴
        - 매 반복마다:
            - calc_diff_pose()로 이동 거리를 계산하여 total_dist에 누적
            - 남은 거리(remained_dist)를 계산하여 피드백으로 발행
            - cmd_vel 토픽으로 이동명령을 발행

        - 0.01초 간격으로 반복(100Hz)
        - 남은 거리가 0.2 미만이면 루프 종료 (목표 도달)

        execute_callback 결과 반환
        - goal_handle.succeed() 를 호출하여 액션이 성공했음을 알림
        - Result 객체를 생서하고 최종 위치(pos_x, pos_y, pos_theta)와 실제 이동 거리(result_dist)를 설정
        - total_dist와 is_first_time을 초기화하여 다음 Goal 요청에 대비
        - result를 반환하면 클라이언트에서 최종 결과를 수신
        """
        feedback_msg = DistTurtle.Feedback()

        msg = Twist()
        msg.linear.x = goal_handle.request.linear_x
        msg.angular.z = goal_handle.request.angular_z

        while True:
            self.total_dist += self.calc_diff_pose()
            feedback_msg.remained_dist = goal_handle.request.dist - self.total_dist
            goal_handle.publish_feedback(feedback_msg)
            self.publisher.publish(msg)
            time.sleep(0.01)

            if feedback_msg.remained_dist < 0.2:
                break

        goal_handle.succeed()
        result = DistTurtle.Result()

        result.pos_x        = self.current_pose.x
        result.pos_y        = self.current_pose.y
        result.pos_theta    = self.current_pose.theta
        result.result_dist  = self.total_dist

        self.total_dist     = 0
        self.is_first_time  = True

        return result

def main(args=None):
    """
    - rp.init()으로 ROS2 초기화
    - MultiThreadedExecutor 를 생성하여 여러 노드를 병렬 처리
    - DistTurtleServer(액션 서버)와 TurtleSub_Action(구독자)를 각각 생성
    - TurtleSub_Action 에 액션 서버 인스턴스를 전달하여 pose 데이터를 유
    - 두 노드를ecutor에 등록 후 spin()으로 실행
    - finally 블록에서 안전하게 정리 (shutdown, destroy_node)

    sub = TurtleSub_Action(ac_server=ac) 의 핵심
    - 스탭 1: ac = DistTurtleServer() 로 액션 서버 노드를 먼저 생성 (self.current_pose 보유)
    - 스탭 2: sub = TurtleSub_Action(ac_server=ac)
    - 효과: sub.ac_server와 ac는 동일한 객체 - sub의 callback()아 pose를 갱신하면 ac가 즉시 그 값을 사용
    - 데이터 흐름: /turtle1/pose 토픽 -> TurtleSub_Action.callback() -> ac_server.current_pose 갱신
                -> DistTurtleServer 가 이동거리 계산에 활용
    """
    rp.init(args=args)

    executor    = MultiThreadedExecutor()
    ac          = DistTurtleServer()
    sub         = TurtleSub_Action(ac_server=ac)

    executor.add_node(sub)
    executor.add_node(ac)

    try:
        executor.spin()
    finally:
        executor.shutdown()
        sub.destroy_node()
        ac.destroy_node()
        rp.shutdown()

if __name__ == "__main__":
    main()