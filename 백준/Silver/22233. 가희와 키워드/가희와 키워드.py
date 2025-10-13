#baekjoon 22233
import sys
input = sys.stdin.readline

N, M = map(int, input().split())

st = set()

for i in range(N):
    s = input().rstrip()
    st.add(s)

for i in range(M):
    s = list(input().rstrip().split(","))
    for j in s:
        st.discard(j)
    
    print(len(st))