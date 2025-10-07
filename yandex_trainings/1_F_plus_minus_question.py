def max_diff(n: int, m: int, grid: list[str]) -> int:
    row_sum = [0] * n
    row_sum_questions = [0] * n

    col_sum = [0] * m
    col_sum_questions = [0] * m

    for i in range(n):
        for j in range(m):
            # print(i)
            # print(grid[i])
            char = grid[i][j]
            if char == '-':
                row_sum[i] -= 1
                col_sum[j] -= 1
            elif char == '+':
                row_sum[i] += 1
                col_sum[j] += 1
            elif char == '?':
                row_sum_questions[i] += 1
                col_sum_questions[j] -= 1

    max_diff = float('-inf')

    for i in range(n):
        for j in range(m):
            diff = row_sum[i] + row_sum_questions[i] - col_sum[j] - col_sum_questions[j]
            if grid[i][j] == '?':
                diff -= 2
            # if diff > max_diff:
            #     print(f"{row_sum_questions[i]=}, {col_sum_questions[j]=}")
            max_diff = max(diff, max_diff)
    return max_diff

import sys

data = sys.stdin.read().splitlines()
n, m = map(int, data[0].split())

# print(data)
print(max_diff(n, m, data[1:]))
