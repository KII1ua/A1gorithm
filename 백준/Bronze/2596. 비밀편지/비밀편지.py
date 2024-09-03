# baekjoon 1025
import sys
input = sys.stdin.readline

N = int(input())
dict = {'000000' : 'A', '001111': 'B', '010011': 'C', '011100': 'D', 
        '100110': 'E', '101001': 'F', '110101': 'G', '111010': 'H'}
letter = input().rstrip()
result = ''
tmp = ''
arr = []
num = 1
cnt = 0
differ = 0

for i in letter:
    tmp += i
    cnt += 1

    if cnt == 6:
        if tmp in dict:
            result += dict[tmp]
        else:
            for word in dict.keys():
                arr = []
                differ = 0
                for j in range(len(word)):
                    if tmp[j] != word[j]:
                        differ += 1
                if differ == 1:     # 다른게 하나만 있을 경우 
                    result += dict[word]
                    arr.append(differ)
                    break
                else:
                    arr.append(differ)
            if 1 not in arr:
                print(num)
                sys.exit()
        num += 1
        cnt = 0
        tmp = ''

print(result)