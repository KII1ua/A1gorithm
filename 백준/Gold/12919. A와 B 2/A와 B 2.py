# baekjoon 12919
import sys
input = sys.stdin.readline

S = input().rstrip()
T = input().rstrip()

def dfs(t): # 문자열 T 리스트를 입력받아
    if t==S:
        print(1)
        sys.exit()
    if len(t)==0:
        return 0
    if t[-1]=='A': # 마지막이 A이 일때
        dfs(t[:-1]) # 제거한 후 재귀
    if t[0]=='B': # 처음이 B 일때
        dfs(t[1:][::-1]) # 제거하고, 뒤집어서 재귀

dfs(T)
print(0)