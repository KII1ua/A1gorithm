# 백준 1157번
a = input().upper()
b = list(set(a))        # set 함수는 중복 제거, 순서가 없음
c = []

for _ in b:
    count = a.count(_)
    c.append(count)


if c.count(max(c)) >= 2:
    print("?")
else:
    print(b[c.index(max(c))])