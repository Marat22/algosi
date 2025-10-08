# https://contest.yandex.ru/contest/80940/problems/B/

a = input()

prev_l = 0
prev_r = 1

for i in range(len(a)):
    l, r = prev_l, prev_r
    if a[i] == 'L':
        l = min(prev_l+1, prev_r+1)
        r = min(prev_r, prev_l+1)
    elif a[i] == 'R':
        l = min(prev_l, prev_r+1)
        r = min(prev_l+1, prev_r+1)
    else:
        l = min(prev_r+2, prev_l+1)
        r = min(prev_r+1, prev_l+2)
    prev_l, prev_r = l, r

print(r)
