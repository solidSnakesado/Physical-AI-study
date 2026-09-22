import cv2
import numpy as np
import argparse
import os
from utils import ARUCO_DICT

# 입력 파라미터 설정
parser = argparse.ArgumentParser()
parser.add_argument("--id", type=int, required=True, help="ID of the ArUco marker")
parser.add_argument("--type", type=str, default="DICT_5X5_100", help="Dictionary type")
parser.add_argument("--output", type=str, required=True, help="Output folder path")
parser.add_argument("--size", type=int, default=200, help="Marker size in pixels")
args = parser.parse_args()

# 타입 확인
if args.type not in ARUCO_DICT:
    print(f"[ERROR] Unsupported dictionary type '{args.type}'")
    exit(1)

# 딕셔너리 로딩
aruco_dict = cv2.aruco.getPredefinedDictionary(ARUCO_DICT[args.type])

# 마커 생성
marker_image = cv2.aruco.generateImageMarker(aruco_dict, args.id, args.size)

# 저장 경로
os.makedirs(args.output, exist_ok=True)
filename = f"{args.type}_id_{args.id}.png"

filepath = os.path.join(args.output, filename)

# 저장
cv2.imwrite(filepath, marker_image)
print(f"[INFO] Marker saved to: {filepath}")

