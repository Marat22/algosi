# https://contest.yandex.ru/contest/80940/problems/C/

def bin_search(intervals, i):
    low = 0
    hi = i - 1
    while low <= hi:
        mid = (low + hi) // 2
        if intervals[mid][1] <= intervals[i][0]:
            if mid + 1 <= hi and intervals[mid + 1][1] <= intervals[i][0]:
                low = mid + 1
            else:
                return mid
        else:
            hi = mid - 1
    return -1


def main(intervals) -> int:
    sorted_intervals = sorted(intervals, key=lambda i: i[1])
    n = len(sorted_intervals)
    p = [bin_search(sorted_intervals, i) for i in range(n)]
    dp = [0] * (n + 1)

    for i in range(1, n + 1):
        include = sorted_intervals[i-1][2]
        if p[i-1] != -1:
            include += dp[p[i-1] + 1]

        exclude = dp[i-1]
        dp[i] = max(include, exclude)
    
    return dp[n]


if __name__ == "__main__":
    import sys
    data = sys.stdin.read().splitlines()
    N = int(data[0])
    intervals = [ tuple(map(float, i.split())) for i in data[1:] ]

    print(main(intervals))
