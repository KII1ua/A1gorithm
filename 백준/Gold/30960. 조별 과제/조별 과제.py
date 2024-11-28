#baekjoon 30960
import sys
input = sys.stdin.readline

N = int(input())
arr = list(map(int, input().split()))
arr.sort()

two, three = 0, float('inf')

for i in range(1, N, 2):
    two = two + arr[i] - arr[i-1]
    three = min(two, three) + arr[i+1] - arr[i]

print(three)