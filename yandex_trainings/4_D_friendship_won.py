# https://contest.yandex.ru/contest/80942/problems/D/

n = int(input())
a = list(map(int, input().split()))


prefix = [0] * (n + 1)
for i in range(n):
    prefix[i + 1] = prefix[i] + a[i]

min_diff = float('inf')
best_l = 1
best_r = 2

l = 1
r = n
while l < r:
    SDv = prefix[l]
    SDm = prefix[n] - prefix[r - 1]
    diff = abs(SDv - SDm)

    if diff < min_diff:
        min_diff = diff
        best_l = l
        best_r = r
    if diff == 0:
        break


    if SDv < SDm:
        l += 1
    else:
        r -=1
    
print(min_diff, best_l, best_r)
