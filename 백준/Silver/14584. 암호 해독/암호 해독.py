# baekjoon 14584
import sys
input = sys.stdin.readline

cipher = input().rstrip()
N = int(input())
word = [input().rstrip() for _ in range(N)]

# a(97) ~ z(122)
alpha = [chr(x) for x in range(97, 123)]

for i in word:      # 단어가 암호문에 있을 경우 해독문이므로 출력하고 종료
    if i in cipher:
        print(cipher)
        sys.exit()

for i in range(1, 26):      # 단어를 하나씩 밀기 위함
    alpha_push = {}         # key(원래 단어) value(변경 단어)
    for j in range(26):
        a = j + i
        if a > 25:          # 26까지 갔을 경우 빼서 a부터
            a -= 26
        alpha_push[alpha[j]] = alpha[a]
    decode = ""
    for k in cipher:            
        decode += alpha_push[k]    
    for l in word:
        if l in decode:
            print(decode)
            sys.exit()