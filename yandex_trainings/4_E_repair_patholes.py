def solve():
    n, m, k = map(int, input().split())
    a = list(map(int, input().split()))

    inc = [0] * (n + 1)
    for _ in range(m):
        l, r = map(int, input().split())
        l -= 1
        inc[l] += 1
        inc[r] -= 1
    
    count = [0] * n
    curr = 0
    for i in range(n):
        curr += inc[i]
        count[i] = curr

    
    indexed = [(count[i], a[i]) for i in range(n)]
    indexed.sort(key=lambda x: x[0], reverse=True)
    total = sum(c * a_val for c, a_val in indexed)

    remaining = k
    for c, a_val in indexed:
        if remaining <= 0:
            break

        reduce = min(remaining, a_val)
        total -= c * reduce
        remaining -= reduce
    

    print(total)



if __name__ == "__main__":
    solve()
