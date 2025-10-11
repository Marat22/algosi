# https://contest.yandex.ru/contest/80940/problems/J/

import sys
from collections import defaultdict

def main():
    data = sys.stdin.read().splitlines()

    N, L = map(int, data[0].split())
    shops = [tuple(map(int, row.split())) for row in data[1:]]

    max_len = max([shop[3] for shop in shops])

    dp = [[float("+inf") for k in range(N)] for _ in range(max(L, max_len)+1)]
    dp_seq = [[defaultdict(int) for k in range(N)] for _ in range(max(L, max_len)+1)]

    res = float("+inf")
    res_seq = float("+inf")

    for s in range(L+1):
        for k in range(N):
            for t in range(0, shops[k][3]+1):
                if t < s:
                    cost = calc_cost(shops[k], t)
                    if k > 0 and dp[s-t][k-1] != float("+inf"):
                        if cost + dp[s-t][k-1] < dp[s][k]:
                            dp[s][k] = min(dp[s][k], cost + dp[s-t][k-1])
                            dp_seq[s][k] = dp_seq[s-t][k-1].copy()
                            dp_seq[s][k][k] = t
                else:
                    cost = calc_cost(shops[k], t)
                    if cost < dp[s][k]:
                        dp[s][k] = min(dp[s][k], cost)
                        dp_seq[s][k] = defaultdict(int)
                        dp_seq[s][k][k] = t

                if s >= L:
                    if dp[s][k] < res:
                        res = min(res, dp[s][k])
                        res_seq = dp_seq[s][k]

    if res == float("+inf"):
        print(-1)
    else:
        print(res)

        print(" ".join([str(res_seq[i]) for i in range(N)]))

def calc_cost(shop: tuple[int, int, int, int], meters: int) -> None:
    assert meters <= shop[3]

    if meters < shop[1]:
        return shop[0] * meters
    else:
        return shop[2] * meters


if __name__ == "__main__":
    main()
