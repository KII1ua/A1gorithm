# baekjoon 10420
import sys
import datetime
input = sys.stdin.readline

dt = datetime.date(2014, 4, 2)
N = int(input())

result = datetime.timedelta(days=N-1) + dt
print(result)