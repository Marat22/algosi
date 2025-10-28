#  https://contest.yandex.ru/contest/80942/problems/G/

def solve():
    n = int(input())
    s = list(map(int, input().split()))
    a = list(map(int, input().split()))

    events = sorted(zip(s,a))

    total_a = sum(a)
    total_sa = sum(si * ai for si, ai, in zip(s, a))

    best_e = events[0][0]
    best_cost = sum(abs(best_e - si) * ai for si, ai in zip(s, a))

    left_a_sum = 0
    left_sa_sum = 0

    for si, ai in events:
        right_a_sum_without_ai = total_a -  left_a_sum - ai
        right_sa_sum_without_ai = total_sa - left_sa_sum - si * ai
        cost_si = si * (left_a_sum - right_a_sum_without_ai) + (right_sa_sum_without_ai - left_sa_sum)

        if cost_si < best_cost or (cost_si == best_cost and si < best_e):
            best_cost = cost_si
            best_e = si
        
        left_a_sum += ai
        left_sa_sum += si * ai
    print(best_e, best_cost)

if __name__ == "__main__":
    solve()
