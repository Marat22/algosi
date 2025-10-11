# https://contest.yandex.ru/contest/80940/problems/E/

import sys

def main():
    data = sys.stdin.read().splitlines() 
    N, K = map(int, data[0].split())

    A = [int(i) for i in data[1].split()]

    cur_sum = 0
    cur_min = float("+inf")
    
    towers = []

    for i in range(len(A)):
        if i < K:
            cur_sum += A[i]
            cur_min = min(cur_min, A[i])
        else:
            # print("i-k",i-K)
            cur_sum -= A[i-K]
            cur_sum += A[i]

            cur_min = min(A[i-K+1:i+1])
            # if A[i-K] == cur_min:
            #     print(f"{i=} {cur_min=}, {A[i-K+1:]=}")

        towers.append(cur_sum * cur_min)
        # print(f"{i=} {towers=}")

    # print(A)
    # print(towers)

    dp = [[0, []] for _ in range(N)]
    for i in range(K-1, N):
        start_of_current_interval = i-K+2
        if i != K-1:
            include = towers[i] + dp[i-K][0]
            exclude = sorted((val, prev_vals) for val, prev_vals in dp[i-K+1:i+1])[-1]

            if include > exclude[0]:
                dp[i][0] = include
                dp[i][1] = dp[i-K][1].copy() + [str(start_of_current_interval)] 
            else:
                dp[i][0] = exclude[0]
                dp[i][1] = exclude[1].copy()

        else:
            dp[i] = [towers[i], [str(start_of_current_interval)]]

    # print()
    # print()
    # print(dp[-3:])
    print(len(dp[-1][1]))
    print(" ".join(dp[-1][1]))
    # print(" ".join(str(i) for i in sorted(dp[-K:])[-1][1]))


if __name__ == "__main__":
    main()
