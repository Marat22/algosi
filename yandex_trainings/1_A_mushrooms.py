input()

masha_weight = 0
max_masha = 0
vasya_weight = 0
min_vasya = float('+inf')

for i, weight in enumerate(map(int, input().split()), start=1):
    if i % 2 == 1:
        vasya_weight += weight
        min_vasya = min(min_vasya, weight)
    else:
        masha_weight += weight
        max_masha = max(max_masha, weight)
# print(f"{vasya_weight=}, {masha_weight=}, {min_vasya=}, {max_masha=}")
if min_vasya < max_masha:
    vasya_weight += -min_vasya + max_masha
    masha_weight += min_vasya - max_masha

# print(f"{vasya_weight=}, {masha_weight=}, {min_vasya=}, {max_masha=}")
print(vasya_weight - masha_weight)