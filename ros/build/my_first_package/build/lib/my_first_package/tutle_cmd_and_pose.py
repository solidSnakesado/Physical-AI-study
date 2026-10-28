"""
/turtle1/pose 토픽만 구독하는 기본 구조
Pose 메시지의 x, y, theta, linear_velocity, augular_velocity 필드를 로깅
단계적으로 기능을 추가하는 방식 - 먼저 하나의 토픽 구독이 동작하는 지 확인 후 확장
"""

import rclpy as rp
from rclpy.node     import Node
from turtlesim.msg  import Pose

class CmdAndPose(Node):
    def __init__(self):
        super().__init__("turtle_cmd_pose")
        self.sub_pose = self.create_subscription(Pose, "turtle1/pose", self.callback_pose, 10)

    def callback_pose(self, msg):
        print(msg)

def main(args=None):
    rp.init(args=args)

    turtle_cmd_pose_node = CmdAndPose()
    rp.spin(turtle_cmd_pose_node)

    turtle_cmd_pose_node.destroy_node()
    rp.shutdown()

if __name__ == "__main__":
    main()