# baekjoon 1764
import sys
input = sys.stdin.readline

N, M = map(int, input().split())

people = {}
st_list = []

for i in range(N + M):
    a = input().rstrip()
    if a not in people:
        people[a] = 1
    else:
        people[a] += 1

for i in people:
    if people[i] > 1:
        st_list.append(i)

st_list.sort()
print(len(st_list))
for i in st_list:
    print(i)
