#  https://contest.yandex.ru/contest/80942/problems/J/

import sys
from math import isclose

def solution():
    line = sys.stdin.readline().strip()
    if not line:
        return
    N, L, W = map(int, line.split())

    models = []
    for i in range(N):
        x, y, vx, vy = map(int, sys.stdin.readline().split())
        models.append((x, y, vx, vy))

    events = []
    num_models = len(models)

    for i in range(num_models):
        for j in range(i + 1, num_models):
            x1, y1, vx1, vy1 = models[i]
            x2, y2, vx2, vy2 = models[j]

            dvx = vx1 - vx2
            dvy = vy1 - vy2
            dx = x2 - x1
            dy = y2 - y1

            if dvx == 0 and dvy == 0:
                continue

            t_collision = None
            if dvx == 0:
                if dx != 0:
                    continue
                if dvy != 0:
                    t_temp = dy / dvy
                    if t_temp > 0:
                        t_collision = t_temp
            elif dvy == 0:
                if dy != 0:
                    continue
                if dvx != 0:
                    t_temp = dx / dvx
                    if t_temp > 0:
                        t_collision = t_temp
            else:
                t_x = dx / dvx
                t_y = dy / dvy
                if isclose(t_x, t_y) and t_x > 0:
                    t_collision = t_x

            if t_collision is not None:
                x_col = x1 + vx1 * t_collision
                y_col = y1 + vy1 * t_collision
                if 0 <= x_col <= L and 0 <= y_col <= W:
                    events.append((t_collision, 'collision', (i, j)))

    for i in range(num_models):
        x0, y0, vx, vy = models[i]
        if vx <= 0:
            continue
        t_finish = (L - x0) / vx
        if t_finish <= 0:
            continue
        y_at_finish = y0 + vy * t_finish
        if 0 < y_at_finish < W:
            events.append((t_finish, 'finish', (i,)))

    for i in range(num_models):
        x0, y0, vx, vy = models[i]
        t_impact = float('inf')
        if vy != 0:
            if vy < 0:
                t_y0 = (0 - y0) / vy
                if t_y0 > 0:
                    x_at_impact = x0 + vx * t_y0
                    if 0 <= x_at_impact <= L:
                        events.append((t_y0, 'impact', (i,)))
            if vy > 0:
                t_yW = (W - y0) / vy
                if t_yW > 0:
                    x_at_impact = x0 + vx * t_yW
                    if 0 <= x_at_impact <= L:
                        events.append((t_yW, 'impact', (i,)))

    events.sort(key=lambda e: e[0])

    active_models = set(range(num_models))
    potential_finishers = set()

    i = 0
    while i < len(events):
        current_time = events[i][0]

        same_time_events = []
        while i < len(events) and isclose(events[i][0], current_time):
            same_time_events.append(events[i])
            i += 1

        models_to_remove = set()
        models_to_finish = set()

        for event_time, event_type, event_data in same_time_events:
            if event_type == 'collision':
                m1, m2 = event_data
                if m1 in active_models and m2 in active_models:
                    models_to_remove.add(m1)
                    models_to_remove.add(m2)
            elif event_type == 'finish':
                m = event_data[0]
                if m in active_models:
                    models_to_finish.add(m)
            elif event_type == 'impact':
                m = event_data[0]
                if m in active_models:
                    models_to_remove.add(m)

        models_to_remove = models_to_remove.intersection(active_models)
        active_models.difference_update(models_to_remove)

        for m in models_to_finish:
            if m in active_models:
                potential_finishers.add((current_time, m))

        finishers_not_collided = models_to_finish - models_to_remove
        active_models.difference_update(finishers_not_collided)


    if not potential_finishers:
        print(0)
        return

    min_finish_time = min([t for t, m in potential_finishers])
    winners = [m for t, m in potential_finishers if isclose(t, min_finish_time)]

    if not winners:
        print(0)
        return

    winners_one_indexed = [w + 1 for w in sorted(winners)]
    print(len(winners_one_indexed))
    print(' '.join(map(str, winners_one_indexed)))


solution()
