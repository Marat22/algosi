# https://contest.yandex.ru/contest/80941/problems/D/

import sys
import bisect

def solve():
    line = sys.stdin.readline().split()
    n = int(line[0])
    p = float(line[1])

    c = list(map(int, sys.stdin.readline().split()))

    indexed_tables = [(c[i], i) for i in range(n)]
    indexed_tables.sort(key=lambda x: x[0])

    best_i = -1
    best_j = -1
    best_diff = float('inf')

    for i in range(n):
        original_idx_i = i
        val_i = c[original_idx_i]
        target_val_for_j = val_i / p

        pos = bisect.bisect_left(indexed_tables, (target_val_for_j, -1))

        candidates = []
        if pos < n:
            val_j, orig_idx_j = indexed_tables[pos]
            if orig_idx_j != original_idx_i:
                candidates.append((orig_idx_j, abs(val_j - target_val_for_j)))
        if pos > 0:
            val_j, orig_idx_j = indexed_tables[pos - 1]
            if orig_idx_j != original_idx_i:
                candidates.append((orig_idx_j, abs(val_j - target_val_for_j)))

        if not candidates:
            if pos + 1 < n:
                val_j, orig_idx_j = indexed_tables[pos + 1]
                if orig_idx_j != original_idx_i:
                    candidates.append((orig_idx_j, abs(val_j - target_val_for_j)))
            if pos - 2 >= 0:
                val_j, orig_idx_j = indexed_tables[pos - 2]
                if orig_idx_j != original_idx_i:
                    candidates.append((orig_idx_j, abs(val_j - target_val_for_j)))

        if candidates:
            best_candidate_idx,_=min(candidates, key=lambda x: x[1])
            current_ratio = val_i / c[best_candidate_idx]
            current_diff = abs(current_ratio - p)

            if current_diff < best_diff:
                best_diff = current_diff
                best_i = original_idx_i
                best_j = best_candidate_idx

    if best_i != -1 and best_j != -1:
        print(best_i + 1, best_j+1)
    else:
        assert False, "whaaat"

if __name__ == "__main__":
   solve()