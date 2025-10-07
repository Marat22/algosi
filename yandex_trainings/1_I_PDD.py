# https://contest.yandex.ru/contest/80939/problems/I/

from collections import deque
import sys

def second_solution(x,y, f,g):
    if x == f and y == g:
        return 0
    vert = calc(x, f)
    horiz = calc(y, g)

    return vert + horiz - 1

def calc(x,f ):
    if x == f:
        up = 0
    elif abs(x - f) == 1:
        up = 1
    else:
        up = 1
        if x < f:
            f -= 1
        else:
            x -= 1
        up += abs(x - f) * 3  
    return up

data = sys.stdin.read().strip().split()
x, y = map(int, data[0:2])
f, g = map(int, data[2:4])
print(second_solution(x,y,f,g))
