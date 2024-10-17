# baekjoon 30804
import sys
from collections import defaultdict
input = sys.stdin.readline
# sys.setrecursionlimit(10**6)

N = int(input())
arr = list(map(int, input().split()))
left, right, cnt = 0, 0, 0
result = 0
dic = defaultdict(int)

while right < N:        # 끝 인덱스가 오른쪽으로 이동
    if dic[arr[right]] == 0:
        cnt += 1
    dic[arr[right]] += 1
    
    while cnt > 2:  # 첫 인덱스가 오른쪽으로 이동
        dic[arr[left]] -= 1
        if dic[arr[left]] == 0:
            cnt -= 1
        left += 1
    
    result = max(result, right - left + 1)
    right += 1

print(result)