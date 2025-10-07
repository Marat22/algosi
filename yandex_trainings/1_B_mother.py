def main():
    a, b, c, v0, v1, v2 = map(int, input().split())
    
    path = set()

    best_time = 100**3

    all_places = ['d', 'p', 's']

    speed_dict = {0: v0, 1: v1, 2: v2}


    def get_time(curr_place, next_place, qty_of_items_in_hands) -> float:
        distance = 0
        road = set([curr_place, next_place])
        if road == set(['d', 's']):
            distance = a
        elif road == set(['d', 'p']):
            distance = b
        elif road == set(['s', 'p']):
            distance = c
        else:
            # print(road)
            assert False

        return distance / speed_dict[qty_of_items_in_hands]

    def dfs(time, state: tuple[str, tuple[int, int], tuple[int, int]]):
        nonlocal best_time

        if state in path:
            return


        # print(len(path) * "    ", state)
        if state[0] == 'd':
            assert state[1][0] == state[1][1] == 0
            if all(state[2]):
                best_time = min(time, best_time)
                return
            
        # print(state)

        path.add(state)
        for next_place in all_places:
            if next_place == state[0]:
                continue

            if next_place == 'd':
                dfs(
                    time + get_time(state[0], next_place, sum(state[1])),
                    (next_place, (0, 0), (state[1][0] or state[2][0], state[1][1] or state[2][1]))
                )
            elif next_place == 's':
                if not state[1][0] and not state[2][0]:
                    dfs(
                        time + get_time(state[0], next_place, sum(state[1])),
                        (next_place, (1, state[1][1]), state[2])
                    )
                dfs(
                    time + get_time(state[0], next_place, sum(state[1])),
                    (next_place, state[1], state[2])
                )
            elif next_place == 'p':
                if not state[1][1] and not state[2][1]:
                    dfs(
                        time + get_time(state[0], next_place, sum(state[1])),
                        (next_place, (state[1][0], 1), state[2])
                    )
                dfs(
                    time + get_time(state[0], next_place, sum(state[1])),
                    (next_place, state[1], state[2])
                )

        path.remove(state)
    dfs(0, ('d', (0,0), (0,0)))
    print(best_time)


main()