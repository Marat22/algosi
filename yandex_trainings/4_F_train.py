#  https://contest.yandex.ru/contest/80942/problems/F/

def solve():
    n, m, x = map(int, input().split())

    events = []


    for i in range(n):
        a, b, v = map(int, input().split())
        if a < b:
            t_enter = (x- b) / v
            t_leave = (x - a) / v
        else:
            t_enter = (b - x) / v
            t_leave = (a - x) / v

        if t_enter > t_leave:
            t_enter, t_leave = t_leave, t_enter

        if t_leave >= 0:
            events.append((max(0, t_enter), 1))
            events.append((t_leave, -1))
        
    events.sort()

    active_trains = 0
    busy_intervals = []
    current_start = None


    for time, delta in events:
        active_trains += delta

        if active_trains > 0 and current_start is None:
            current_start = time
        elif active_trains == 0 and current_start is not None:
            if current_start < time:
                busy_intervals.append((current_start, time))
            current_start = None
    
    
    if busy_intervals:
        merged = [busy_intervals[0]]
        for start, end in busy_intervals[1:]:
            if start <= merged[-1][1]:
                merged[-1] =  (merged[-1][0], max(merged[-1][1], end))
            else:
                merged.append((start, end))
        busy_intervals = merged
        
    cars = list(map(int, input().split()))

    import bisect

    start_times = [interval[0] for interval in busy_intervals]
    

    for car_time in cars:
        result_time = car_time

        idx = bisect.bisect_right(start_times, car_time)

        if idx > 0:
            start, end = busy_intervals[idx - 1]
            if start <= car_time < end:
                result_time = end
        print(f"{result_time:.9f}")


solve()