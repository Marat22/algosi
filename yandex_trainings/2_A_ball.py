# https://contest.yandex.ru/contest/80940/problems/H/

N = int(input())

steps = [0] * max(2+N, 4)

steps[0] = 0
steps[1] = 1
steps[2] = steps[2-1] + 1
steps[3] = steps[3-1] + steps[3-2] + 1

for i in range(4, N+1):
    steps[i] = steps[i-3] + steps[i-2] + steps[i-1]

print(steps)
print(steps[N])
