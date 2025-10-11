# https://contest.yandex.ru/contest/80940/problems/F/

import sys

data = sys.stdin.read().splitlines()

N = int(data[0])
rows = data[1:]

prev_vals = [0,0,0]
prev_reachable = [True,True,True]

for row in rows:
    cur_line = [0,0,0]
    cur_reachable = [True, True, True]
    for i in range(3):
        min_inx = max(0, i-1)
        max_prev_line_inx = min(2, i+1) + 1
        val = max( prev_vals[ min_inx : max_prev_line_inx ] )

        # print(f"{i} {prev_vals[ max(0, i-1) : min(2, i+1) + 1]}")

        if row[i] == 'W':
            val = 0

        elif row[i] == 'C':
            val += 1

        cur_reachable[i] = row[i] != 'W' and any(prev_reachable[ min_inx : max_prev_line_inx ])
        # print(f"{i} {prev_reachable} {cur_reachable[i]}")

        # val *= cur_reachable[i]
        
        cur_line[i] = val

    # print(cur_reachable)
    if not any(cur_reachable):
        # print(row)
        # prev_vals = [0,0,0]
        # print(max([*prev_vals]))
        # print(cur_line)
        break
        

    prev_reachable = cur_reachable
    prev_vals = cur_line

print(max(prev_vals))
