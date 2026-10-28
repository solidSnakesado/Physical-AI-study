"""
- create_service(MultiSpawn, "multi_spawn", callback_service): 서비스 서버 생성
- 서비스 이름 multi_spawn 으로 요청을 수신
- callback_service: 요청이 들어오면 실행되는 콜백 함수
- 초기 버전에서는 단순히 거북이를 spawn 하는 기본 동작만 구현

teleport_absolute 서비스 클라이언트
- teleport_absolute: turtlesim 이 제공하는 서비스로, 거북이를 지정한 좌표(x, y, theta)로 즉시 이동
- 서비스 서버(my_service_server) 안에서 클라이언트를 만들어 turtlesim의 teleport 서비스를 호출
- create_client(TeleportAbsolute, "/turtle1/teleport_absolute")로 클라이언트 생성
- 서비스 서버가 동시에 다른 서비스의 클라이언트 역할도 수행하는 패턴

최종 my_service_server.py import 구문
- from my_first_package_msgs.srv import MultiSpawn  : 커스텀 서비스 정의
- from turtlesim.srv import Spawn, TeleportAbsoluteL: turtlesim 서비스들
- import math       : 삼각함수(cos,sin)와 pi 사용을 위해 필요
- import rclpy 등   : 기본 ROS2 Python 라이브러리

"""

from my_first_package_msgs.srv  import MultiSpawn
from turtlesim.srv              import TeleportAbsolute
from turtlesim.srv              import Spawn

import time
import rclpy as rp
import numpy as np
from rclpy.node                 import Node

class MultiSpawning(Node):
    def __init__(self):
        """
        MultiSpawning.__init__ 구조
        - create_service(MultiSpawn, "multi_spawn", self.callback_service): 서비스 서버 생성
        - create_client(Spawn, "spawn"): 거북이 생성을 위한 클라이언트
        - create_client(TeleportAbsolute, "/turtle1/teleport_absolute"): 거북이 이동을 위한 클라이언트
        - 하나의 노드에서 서비스 서버 1개 + 서비스 클라이언트 2개를 동시에 운영하는 구조
        """
        super().__init__("multi_spawn")
        self.server         = self.create_service(MultiSpawn, "multi_spawn", self.callback_service)
        self.teleport       = self.create_client(TeleportAbsolute, "/turtle1/teleport_absolute")
        self.spawn          = self.create_client(Spawn, "/spawn")
        self.req_teleport   = TeleportAbsolute.Request()
        self.req_spawn      = Spawn.Request()
        self.center_x       = 5.54
        self.center_y       = 5.54

    def callback_service(self, request, response):
        """
        callback_service: spawn + teleport 반속 실행
        - 요청받은 num 만큼 반복하면서:
            - calc_position(i, num) 으로 좌표 계산
            - spawn 클라이언트로 새 거북이 생성
            - teleport_absolute 클라이언트로 거북이를 원 위의 좌표로 이동
        - 각 단계에서 future.result() 로 비동기 호출의 완료를 대기
        - 응답(response)의 x, y, theta 배열에 배치된 좌표를 추가하여 반환
        """
        x, y, theta = self.calc_position(request.num, 3)

        for n in range(len(theta)):
            self.req_spawn.x        = x[n] + self.center_x
            self.req_spawn.y        = y[n] + self.center_y
            self.req_spawn.theta    = theta[n]
            self.spawn.call_async(self.req_spawn)

        response.x      = x
        response.y      = y
        response.theta  = theta

        return response

    def calc_position(self, n, r):
        """
        calc_position: 원형 좌표 계산
        - gap_theta = 2 * math.pi / num: 거북이 간 각도 간격 계산
        - x = cx + r * math.cos(i * gap_theta): 각 거북이의 x좌표
        - y = cx + r * math.sin(i * gap_theta): 각 거북이의 y좌표
        - cx, cy는 turtlesim 화면의 중심 좌표 (약 5.544)
        - r은 배치 원의 반지름 - 화면을 벗어나지 않을 크기로 설정
        - Jupyter에서 검증한 수학 공식 그대로 ROS2 코드에 적용
        """
        gap_theta = 2 * np.pi / n
        theta = [gap_theta * n for n in range(n)]
        x = [r * np.cos(th) for th in theta]
        y = [r * np.sin(th) for th in theta]

        return x, y, theta

def main(args=None):
    rp.init(args=args)
    multi_spawn = MultiSpawning()
    rp.spin(multi_spawn)
    rp.shutdown()

if __name__ == "__main__":
    main()