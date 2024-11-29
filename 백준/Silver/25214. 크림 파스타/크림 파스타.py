# baekjoon 25214
import sys
input = sys.stdin.readline

N = int(input())
arr = list(map(int, input().split()))
num = arr[0]
tmp = 0
result = [0]

# for i in range(1, N):
#     num = min(arr[i], num)
#     tmp = max(result[i-1], tmp)
#     result.append(max(arr[i] - num))

# print(result)
for i in range(1, N):
    if arr[i] < num:
        num = arr[i]
    
    if arr[i] - num >= tmp:
        result.append(arr[i] - num)
        tmp = arr[i] - num
    else:
        result.append(tmp)

for i in range(len(result)):
    print(result[i], end = " ")