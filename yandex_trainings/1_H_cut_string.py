# https://contest.yandex.ru/contest/80939/problems/H/

import sys
from collections import defaultdict, deque

def main():
    data = sys.stdin.read().splitlines()

    n, k = map(int, data[0].split())

    length = n // k

    s = data[1]
    parts = defaultdict(deque)

    for i, part in enumerate(data[2:], start=1):
        parts[part].append(str(i))

    res = []
    while s:
        res.append(
            parts[s[:length]].popleft()
        )
        s = s[length:]

    print(" ".join(res))


if __name__ == "__main__":
    main()
