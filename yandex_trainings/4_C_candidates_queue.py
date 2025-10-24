# https://contest.yandex.ru/contest/80942/problems/C/

class FenwickTree:
    def __init__(self, n: int):
        self.n = n
        self.tree = [0] * (n + 1)
    
    def update(self, i, delta):
        i += 1
        while i < self.n:
            self.tree[i] += delta
            i += i & (-i)

    def query(self, i):
        if i < 0:   return 0
        i += 1
        s = 0
        while i > 0:
            s += self.tree[i]
            i -= i & (-i)
        return s
    
    def range_query(self, l, r):
        if l > r:
            return 0
        return self.query(r) - (self.query(l - 1) if l > 0 else 0)

n, x = map(int, input().split())
elements = list(map(int, input().split()))

max_size = n + 100000
fenwick = FenwickTree(max_size)

for i in range(n):
    if elements[i] >= x:
        fenwick.update(i, 1)

offset = 0

m = int(input())


for _ in range(m):
    query = list(map(int, input().split()))

    if query[0] == 1:
        a = query[1]
        idx = len(elements)
        elements.append(a)
        if a >= x:
            fenwick.update(idx, 1)
    elif query[0] == 2:
        offset += 1
    
    else:
        k = query[1]
        if k == 0:
            print(0)

        else:
            print(fenwick.range_query(offset, offset + k - 1))
