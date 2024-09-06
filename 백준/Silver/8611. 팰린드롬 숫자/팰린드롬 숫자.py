# baekjoon 8611
import sys
input = sys.stdin.readline

N = int(input())
num = False

for i in range(2, 11):
    m = N
    tmp = ""
    while m > 0:
        tmp = str(m % i) + tmp
        m = m // i
    if tmp == tmp[::-1]:
        print("{} {}".format(i, tmp))
        num = True

if num == False:
    print("NIE")