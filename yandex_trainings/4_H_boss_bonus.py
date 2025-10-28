#  https://contest.yandex.ru/contest/80942/problems/H/

import sys

data = sys.stdin.read().splitlines()

n = int(data[0])
a = list(map(int, data[1].split()))

diffs = [0] * (n + 2)

for j in range(n):
    l = j + 1
    r = min(n - 1, j + a[j] - 1)
    if l <= r:
        diffs[l] += 1
        diffs[r + 1] -= 1

tot = 0
curr = 0

for i in range(n):
    curr += diffs[i]
    bonus = curr * a[i]
    tot += bonus


print(tot)
