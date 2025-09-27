// https://leetcode.com/problems/valid-tree
// https://neetcode.io/problems/valid-tree

class Solution {
public:
    bool dfs(
        int cur,
        int prev,
        unordered_map<int, vector<int>>& adj,
        unordered_set<int>& visited
        ) {
            if (visited.find(cur) != visited.end()) {
                return false;
            }

            visited.insert(cur);
            for (int next_val : adj[cur]) {
                if (next_val != prev) {
                    if (dfs(next_val, cur, adj, visited) == false) {
                        return false;
                    }
                }
            }

            return true;
        }

    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() == 0) {
            return true;
        }
        unordered_map<int, vector<int>> adj;

        for (vector<int> edge : edges) {
                adj[edge[0]].push_back(edge[1]);
                adj[edge[1]].push_back(edge[0]);

        }

        unordered_set<int> visited;

        return dfs(0, -1, adj, visited) && n == visited.size();
    }
};
