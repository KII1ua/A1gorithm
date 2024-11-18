#baekjoon 14731
import sys
input = sys.stdin.readline

N = int(input())
result = 0

def divied(c, k):
    num = c * k
    tmp = 1
    st = 2
    k -= 1
    while k > 0:
        if k % 2 == 1:
            tmp *= st % 1000000007
            k -= 1
        st *= st % 1000000007
        k //= 2
    return tmp * num

for i in range(N):
    c, k = map(int, input().split())
    result += divied(c, k)

print(result % 1000000007)