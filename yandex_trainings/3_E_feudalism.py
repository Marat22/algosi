# https://contest.yandex.ru/contest/80941/problems/E/

from collections import defaultdict

def solve():
    n = int(input())
    p = [0] * n
    for i in range(1, n):
        p[i] = int(input())

    a = list(map(int, input().split()))

    # Build the tree
    children = defaultdict(list)
    for i in range(1, n):
        children[p[i]].append(i)

    total_ops = 0

    def dfs(v):
        nonlocal total_ops
        # Calculate S[v] = -a[v]
        S_v = -a[v]
        # Calculate ops[v] = S[v] - sum(S[c] for c in children[v])
        ops_v = S_v
        for c in children[v]:
            S_c = dfs(c)
            ops_v -= S_c
        # Add the number of operations for this specific path
        total_ops += abs(ops_v)
        # Return S[v] for use by parent
        return S_v

    dfs(0)
    print(total_ops)

solve()