# https://contest.yandex.ru/contest/80941/problems/H/

from collections import defaultdict
import sys

sys.setrecursionlimit(10**7)

def DFS_subtree_weight(v, p, adj, a, subtree_weight):
    """Вычисляет вес поддерева для каждой вершины."""
    subtree_weight[v] = a[v]
    for u in adj[v]:
        if u != p:
            DFS_subtree_weight(u, v, adj, a, subtree_weight)
            subtree_weight[v] += subtree_weight[u]


def find_best_centroid(n, adj, a):
    total_weight = sum(a)
    subtree_weight = [0] * (n + 1)
    
    DFS_subtree_weight(1, -1, adj, a, subtree_weight)
    best_vertex = 1
    min_max_weight = float('inf')

    for v in range(1, n + 1):
        max_component_weight = a[v] 
        for u in adj[v]:
            if subtree_weight[u] < subtree_weight[v]:
                component_weight = subtree_weight[u]
            else:
                component_weight = total_weight - subtree_weight[v]
            
            max_component_weight = max(max_component_weight, component_weight)
        
        if max_component_weight < min_max_weight:
            min_max_weight = max_component_weight
            best_vertex = v
            
    return best_vertex

n = int(input())
a_vals = list(map(int, input().split()))
a = [0] + a_vals
adj = defaultdict(list)
for _ in range(n - 1):
    v, u = map(int, input().split())
    adj[v].append(u)
    adj[u].append(v)

result = find_best_centroid(n, adj, a)

print(result)