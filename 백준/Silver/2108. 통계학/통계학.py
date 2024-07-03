# baekjoon 1966
import sys
input = sys.stdin.readline

N = int(input())
lst = []

for _ in range(N):
    _ = int(input())
    lst.append(_)

srt_lst = sorted(lst)
#산평
print(round(sum(lst) / len(lst)))

#중앙값
print(srt_lst[len(srt_lst) // 2])

#최빈값
dic_lst = dict()
for i in srt_lst:
    if i in dic_lst:
        dic_lst[i] += 1
    else:
        dic_lst[i] = 1

tmp = max(dic_lst.values())     # 빈도수 최댓값 저장
max_lst = []        # 최댓값 저장 배열

for i in dic_lst:
    if tmp == dic_lst[i]:
        max_lst.append(i)

if len(max_lst) > 1:
    print(max_lst[1])
else:
    print(max_lst[0])

#범위
print(max(lst) - min(lst))