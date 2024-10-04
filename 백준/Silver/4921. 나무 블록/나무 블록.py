#baekjoon 13251
import sys
input = sys.stdin.readline
res = 0

while True:
    a = int(input())
    if a == 0:
        break
    
    a = str(a)
    cnt = 0     # 1의 개수
    cnt1 = 0    # 2의 개수
    res += 1
    visited = False

    if a[0] not in ['1'] or a[-1] not in ['2']:
        print("{}. NOT".format(res))
        continue
    if a.count('1') != 1 or a.count('2') != 1:
        print("{}. NOT".format(res))
        continue

    for i in range(1, len(a)):
        # if a[i] == '1':
        #     cnt += 1
        # elif a[i] == '2':
        #     cnt1 += 1
        if a[i] == '3':
            if a[i-1] not in ['4', '6'] or a[i+1] not in ['4', '5']:
                print("{}. NOT".format(res))
                visited = True
                break
            if visited == True:
                break
        elif a[i] == '4':
            if a[i-1] not in ['1', '3'] or a[i+1] not in ['2', '3']:
                print("{}. NOT".format(res))
                visited = True
                break
            if visited == True:
                break
        elif a[i] == '5':
            if a[i-1] not in ['1', '3'] or a[i+1] not in ['8']:
                print("{}. NOT".format(res))
                visited = True
                break
            if visited == True:
                break
        elif a[i] == '6':
            if a[i-1] not in ['8'] or a[i+1] not in ['2', '3']:
                print("{}. NOT".format(res))
                visited = True
                break
            if visited == True:
                break
        elif a[i] == '7':
            if a[i-1] not in ['8'] or a[i+1] not in ['8']:
                print("{}. NOT".format(res))
                visited = True
                break
            if visited == True:
                break
        elif a[i] == '8':
            if a[i-1] not in ['5', '7'] or a[i+1] not in ['6', '7']:
                print("{}. NOT".format(res))
                visited = True
                break
            if visited == True:
                break
        
    if visited == False:
        print("{}. VALID".format(res))