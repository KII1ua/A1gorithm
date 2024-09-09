# baekjoon 2805
import sys
input = sys.stdin.readline

N, M = map(int, input().split())
tree = list(map(int, input().split()))

tree.sort()

start = 0
end = tree[-1]
rst = 0

while start <= end:
    result = 0      # 가져갈 나무 개수 초기화

    mid = (start + end) // 2
    for i in range(len(tree)):
        if tree[i] - mid < 0:       # 음수일 경우 가져갈 나무가 없음
            continue
        else:
            result += tree[i] - mid

    if result >= M:  # 자른 나무가 더 클 경우 
        rst = max(rst, mid)
        start = mid + 1
    else:
        end = mid - 1

print(rst)