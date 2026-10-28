"""
/turtle1/pose 토픽만 구독하는 기본 구조
Pose 메시지의 x, y, theta, linear_velocity, augular_velocity 필드를 로깅
단계적으로 기능을 추가하는 방식 - 먼저 하나의 토픽 구독이 동작하는 지 확인 후 확장

- pose_callbackL    : /turtle1/pose 수신 시 CmdAndPoseVel 의 pose_x, pose_y, linear_vel, angular_vel 필드를 업데이트
- cmd_vel_callback  : /turtle1/cmd_vel 수신 시 CmdAndPoseVel 의 cmd_vel_linear, cmd_vel_angular 필드를 업데이트
- 타이머가 1초마다 timer_callback 을 호출하고, 그 안에서 publisher.publish() 로 최신 합산 데이터를 발행
- 두 콜백이 하나의 메시지 객체(self.cmd_pose_msg)를 공유하는 구조
"""

import rclpy as rp
from rclpy.node                 import Node
from turtlesim.msg              import Pose
from geometry_msgs.msg          import Twist
from my_first_package_msgs.msg  import CmdAndPoseVel

class CmdAndPose(Node):
    def __init__(self):
        super().__init__("turtle_cmd_pose")
        self.sub_pose       = self.create_subscription(Pose, "turtle1/pose", self.callback_pose, 10)
        self.sub_cmdvel     = self.create_subscription(Twist, "turtle1/cmd_vel", self.callback_cmd, 10)
        self.cmd_pose       = CmdAndPoseVel()
        self.timer_period   = 1.0
        self.timer          = self.create_timer(self.timer_period, self.timer_callback)
        self.publisher      = self.create_publisher(CmdAndPoseVel, "/cmd_and_pose", 10)

    def callback_pose(self, msg):
        self.cmd_pose.pose_x = msg.x
        self.cmd_pose.pose_y = msg.y
        self.cmd_pose.linear_vel = msg.linear_velocity
        self.cmd_pose.angular_vel = msg.angular_velocity
        print(self.cmd_pose)

    def callback_cmd(self, msg):
        self.cmd_pose.cmd_vel_linear = msg.linear.x
        self.cmd_pose.cmd_vel_angular = msg.angular.z
        print(self.cmd_pose)

    def timer_callback(self):
        self.publisher.publish(self.cmd_pose)

def main(args=None):
    rp.init(args=args)

    turtle_cmd_pose_node = CmdAndPose()
    rp.spin(turtle_cmd_pose_node)

    turtle_cmd_pose_node.destroy_node()
    rp.shutdown()

if __name__ == "__main__":
    main()