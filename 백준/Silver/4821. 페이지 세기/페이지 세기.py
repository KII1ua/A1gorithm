# baekjoon 4821
import sys
input = sys.stdin.readline

while True:
    lst = set()

    a = int(input())

    if a == 0:
        sys.exit()

    b = input().rstrip()
    
    b = b.split(",")

    for i in b:
        i = i.split("-")
        if len(i) == 2:
            if int(i[0]) <= int(i[1]):
                if int(i[1]) <= a:
                    for k in range(int(i[0]), int(i[1])+1):
                        lst.add(k)
                else:
                    for k in range(int(i[0]), a+1):
                        lst.add(k)
        else:
            if int(i[0]) <= a:
                lst.add(int(i[0]))
    print(len(lst))