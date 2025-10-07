import sys
from collections import Counter

data = sys.stdin.read().splitlines()

n, k = map(int, data[0].split())
problems = Counter(data[1].split())

filler = max(0, k - len(problems))
res = []

for theme, qty in problems.items():
    if not k:
        break
    qty -= 1
    k -= 1
    res.append(theme)
    if filler:
        to_add = min(filler, qty)
        qty -= to_add
        filler -= to_add
        k -= to_add
        res.extend([theme] * to_add)

print(" ".join(res))
