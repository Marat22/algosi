# https://contest.yandex.ru/contest/80941/problems/F/

import sys

sys.setrecursionlimit(10**7)

def solution():

    import sys
    data = sys.stdin.read().splitlines()

    N = int(data[0])
    
    g = [[] for _ in range(N+1)]
    start = [0] * (N + 1)
    finish = [0] * (N + 1)
    used = set()

    root = None
    for i, v in enumerate(map(int, data[1].split()), start=1):
        if v == 0:
            root = i
        else:
            g[v].append(i)

    time = 0

    def DFS(v: int) -> None:
        nonlocal time

        used.add(v)
        time+=1
        start[v] = time
        for kid in g[v]:
            if kid not in used:
                DFS(kid)
        time +=  1
        finish[v] = time
    
    DFS(root)

    to_check = [(*map(int,nodes.split()),) for nodes in data[3:] ]

    for a, b in to_check:
        if start[a] < start[b] and finish[b] < finish[a]:
            print(1)
        else:
            print(0)


if __name__ == "__main__":
    solution()
