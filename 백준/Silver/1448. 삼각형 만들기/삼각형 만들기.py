#baekjoon 28324
import sys
from collections import deque
input = sys.stdin.readline

N = int(input())
arr = []
tmp = 0

for _ in range(N):
    a = int(input())
    arr.append(a)

arr.sort(reverse=True)

for i in range(0, N-3+1):
    if arr[i] + arr[i+1] > arr[i+2] and arr[i] + arr[i+2] > arr[i+1] and arr[i+1] + arr[i+2] > arr[i]:
        print(arr[i] + arr[i+1] + arr[i+2])
        sys.exit()
    # elif arr[i] == arr[i+1] or arr[i+1] == arr[i+2]:  # 이등변
    #     print(arr[i] + arr[i+1] + arr[i+2])
    #     sys.exit()
    
print(-1)
# else:
#     for j in range(0, N-3):
#         if arr[j] + arr[j+1] > arr[j+2] and arr[j] + arr[j+2] > arr[j+1] and arr[j+1] + arr[j+2] > arr[j]:
#             print(arr[j] + arr[j+1] + arr[j+2])
#             sys.exit()
#         elif arr[j] == arr[j+1] or arr[j+1] == arr[j+2]:  # 이등변
#             print(arr[j] + arr[j+1] + arr[j+2])
#             sys.exit()
#     print(-1)