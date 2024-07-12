#baekjoon 13866
import sys
input = sys.stdin.readline

level = list(map(int, input().split()))

level.sort()

print(abs((level[-1] + level[0]) - (level[1] + level[2])))
