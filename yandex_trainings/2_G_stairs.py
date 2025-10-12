# https://contest.yandex.ru/contest/80940/problems/G/

def main(N: int):
    dp = [[0 for _ in range(0, N+1)] for _ in range(0, N+1)]

    dp[0][0] = 1

    for total in range(1, N+1):
        for first_row in range(1, N+1):
            if first_row <= total:
                for next_row in range(1, first_row+1):
                    if first_row - next_row < first_row:
                        dp[total][first_row] += dp[total-first_row][first_row - next_row]

    print(sum(dp[N]))

main(int(input()))
