from collections import defaultdict

all_chars = defaultdict(int)
total_sum = 0
res = 1

for c in input():
    all_chars[c] += 1
    total_sum += 1

for c, qty in all_chars.items():
    total_sum -= qty
    res += qty * total_sum

print(res)
