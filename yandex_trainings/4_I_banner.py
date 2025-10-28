#  https://contest.yandex.ru/contest/80942/problems/I/

import math


def gen_possible_solutions(d):
    solutions = []
    sqrt_d = int(math.sqrt(d)) + 1
    for dx in range(-sqrt_d, sqrt_d + 1):
        dx_sq = dx * dx
        if dx_sq > d:
            continue
        dy_sq = d - dx_sq
        dy_float = math.sqrt(dy_sq)
        dy_int = int(round(dy_float))
        if dy_int * dy_int == dy_sq:
            solutions.append((dx, dy_int))
            if dy_int != 0:
                solutions.append((dx, -dy_int))
    return solutions


def calc_count():
    count = 0
    for x, y in points_list:
        for dx, dy in shifts:
            target = (x + dx, y + dy)
            if target in points_set and (x, y) != target:
                count += 1
    return count // 2


if __name__ == "__main__":
    n, d = map(int, input().split())
    points_set = set()
    points_list = []
    for _ in range(n):
        x, y = map(int, input().split())
        points_set.add((x, y))
        points_list.append((x, y))
    shifts = gen_possible_solutions(d)

    print(calc_count())
    