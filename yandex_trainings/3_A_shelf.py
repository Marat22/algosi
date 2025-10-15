# https://contest.yandex.ru/contest/80941/problems/A/

def main(a: int, b: int, S: int) -> int:
    if a < b:
        z = b - a
        v = 0
    else:
        z = 0
        v = a - b

    lo = 0
    hi = S
    while lo <= hi:
        mid = lo + (hi - lo) // 2
        mb_S = (z + mid) * (v + mid)

        if mb_S == S:
            print(z + mid + a)
            break
        elif mb_S < S:
            lo = mid + 1
        else:
            hi = mid - 1
    else:
        print('-1')


if __name__ == "__main__":
    import sys
    main(*map(int, sys.stdin.read().split()))
