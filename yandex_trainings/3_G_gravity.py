# https://contest.yandex.ru/contest/80941/problems/G/

def solve(n: int, a: list[int], m: int, b:list[int]):
    def BIN_search_ge(arr, x):
        lo, hi = 0, len(arr)
        while lo < hi:
            mid = (lo + hi) // 2
            if arr[mid] >= x:
                hi = mid
            else:
                lo = mid + 1
        return lo
    
    b_after = sorted(b)
    b_start = [0] * (len(b_after) + 1)

    a_after = sorted(a)
    a_start = [0] * (len(a_after) + 1)
    for i in range(len(b_after)):
        b_start[i+1] = b_start[i] + b_after[i]
    fixed_sum_a = []
    for ai in a:
        pos = BIN_search_ge(b_after, ai)
        fixed_sum_a.append(
            (ai * pos - b_start[pos]) 
            + ((b_start[len(b_after)] - b_start[pos]) - ai * (len(b_after) - pos)))
    for i in range(len(a_after)):
        a_start[i+1] = a_start[i] + a_after[i]

    fixed_sum_b = []
    for bj in b:
        pos = BIN_search_ge(a_after, bj)
        fixed_sum_b.append(
            (bj * pos - a_start[pos])
            + ((a_start[len(a_after)] - a_start[pos]) - bj * (len(a_after) - pos))
            )


    result = 0
    for i in range(n):
        result += (i + 1) * fixed_sum_a[i]
    for j in range(m):
        result -= (j + 1) * fixed_sum_b[j]
    
    print(result)

if __name__ == "__main__":
    
    n = int(input())
    a = list(map(int, input().split()))
    m = int(input())
    b = list(map(int, input().split()))
    solve(n,a,m,b)

