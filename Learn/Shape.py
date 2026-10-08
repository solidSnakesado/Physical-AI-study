from abc import ABC, abstractmethod
import math
from typing import override


# 인터페이스 역할: 추상 메서드만 가진 추상 클래스
class Drawable(ABC):
    @abstractmethod
    def draw(self):
        pass


class Resizable(ABC):
    @abstractmethod
    def resize(self, ratio):
        pass


# 추상 클래스(부모): 공통 속성·메서드 + 자식이 반드시 구현할 추상 메서드
class Shape(Drawable):
    def __init__(self, name):
        self.name = name

    # 추상 메서드: 자식이 반드시 재정의
    @abstractmethod
    def get_area(self):
        pass

    @abstractmethod
    def get_perimeter(self):
        pass

    # 기본 구현이 있는 메서드: 자식이 선택적으로 재정의
    def draw(self):
        print(f"[{self.name}] 도형을 그립니다.")

    # 일반 메서드: 모든 자식이 그대로 사용
    def print_info(self):
        print(f"{self.name} | 넓이: {self.get_area():.2f} | 둘레: {self.get_perimeter():.2f}")


# 자식 클래스 1: 원 (다중 상속으로 인터페이스 구현)
class Circle(Shape, Resizable):
    def __init__(self, radius):
        super().__init__("원")      # 부모 클래스의 생성자 호출
        self.radius = radius

    @override
    def get_area(self):
        return math.pi * self.radius ** 2

    @override
    def get_perimeter(self):
        return 2 * math.pi * self.radius

    @override
    def draw(self):
        print(f"○ 반지름 {self.radius}인 원을 그립니다.")

    @override
    def resize(self, ratio):
        self.radius *= ratio


# 자식 클래스 2: 사각형
class Rectangle(Shape, Resizable):
    def __init__(self, width, height, name="사각형"):
        super().__init__(name)
        self.width = width
        self.height = height

    def get_area(self):
        return self.width * self.height

    def get_perimeter(self):
        return 2 * (self.width + self.height)

    def draw(self):
        super().draw()  # 부모의 draw도 호출
        print(f"□ {self.width} x {self.height} 사각형")

    def resize(self, ratio):
        self.width *= ratio
        self.height *= ratio


# 자식 클래스 3: 정사각형 (사각형을 다시 상속 → 다단계 상속)
class Square(Rectangle):
    def __init__(self, side):
        super().__init__(side, side, "정사각형")

    def draw(self):
        print(f"■ 한 변 {self.width}인 정사각형")


# 자식 클래스 4: 삼각형 (Resizable 미구현, draw 재정의 안 함)
class Triangle(Shape):
    def __init__(self, a, b, c):
        super().__init__("삼각형")
        self.a, self.b, self.c = a, b, c

    def get_perimeter(self):
        return self.a + self.b + self.c

    def get_area(self):
        s = self.get_perimeter() / 2  # 헤론의 공식
        return math.sqrt(s * (s - self.a) * (s - self.b) * (s - self.c))


if __name__ == "__main__":
    # Shape("x")  # TypeError: 추상 클래스는 인스턴스 생성 불가

    shapes = [Circle(3), Rectangle(4, 5), Square(2), Triangle(3, 4, 5)]

    print("=== 다형성: 부모 타입으로 자식 메서드 호출 ===")
    for s in shapes:
        s.draw()
        s.print_info()
        print()

    print("=== 인터페이스 타입으로 다루기 ===")
    for s in shapes:
        if isinstance(s, Resizable):  # 인터페이스 구현 여부 확인
            s.resize(2)
            print("2배 확대 → ", end="")
            s.print_info()
        else:
            print(f"{s.name}은(는) 크기 조절 불가")