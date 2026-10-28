"""
- MultiThreadedExcutor 를 import 하여 사용
- executor = MultiThreadedExcutor() 로 멀티스레드 실행기 생성
- executor.add_node() 로 여러 노드를 하나의 실행기에 등록
- executor.spin() 으로 모든 노드의 콜백을 병렬처리
"""

import rclpy as rp
from rclpy.executors                import MultiThreadedExecutor
from rclpy.node                     import Node

from my_first_package.my_publisher  import TurtlesimPublisher
from my_first_package.my_subscriber import TurtlesimSubscriber

def main(args=None):
    rp.init()

    sub = TurtlesimSubscriber()
    pub = TurtlesimPublisher()

    executor = MultiThreadedExecutor()

    executor.add_node(sub)
    executor.add_node(pub)

    try:
        executor.spin()
    finally:
        executor.shutdown()
        pub.destroy_node()
        rp.shutdown()

if __name__ == "__main__":
    main()