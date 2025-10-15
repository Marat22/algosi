# https://contest.yandex.ru/contest/80941/problems/B/

import sys

def main(nodes: list[list[int]]) -> int:
    to_explore = []

    for node, neighbors in enumerate(nodes[1:], start=1):
        if len(neighbors) == 1:
            # node len prev
            to_explore.append((node, 0, 0))

    explored = {}

    def explore(node: tuple[int, int, int]) -> int | list[tuple[int,int,int]]:
        n = node[0]
        length = node[1]
        prev = node[2]
        
        if n in explored:            
            return explored[n] + length
 
        explored[n] = length

        next_to_explore = []

        for neighbor in nodes[n]:
            if neighbor == prev:
                continue
            next_to_explore.append((neighbor, length+1, n))
        
        return next_to_explore

    while to_explore:
        new_to_explore = []
        for n in to_explore:
            res = explore(n)
            if isinstance(res, int):
                return res
            else:
                new_to_explore.extend(res)
        to_explore = new_to_explore

    assert False


if __name__ == "__main__":
    data = sys.stdin.read().splitlines()
    nodes_num = int(data[0])
    nodes_ = [[] for _ in range(nodes_num+1)]

    for edge in data[1:]:
        n1, n2 = map(int, edge.split())

        nodes_[n1].append(n2)
        nodes_[n2].append(n1)

    
    print(main(nodes_))

