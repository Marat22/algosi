// https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/
// https://neetcode.io/problems/count-connected-components

class Solution {
public:
    void dfs(
        int i,
        unordered_map<int, vector<int>>& adj
    ) {
        if (adj.find(i) == adj.end()) {
            return;
        }
        vector<int> nodes = adj[i];

        adj.erase(i);

        for (int node : nodes) {
            dfs(node, adj);
        }        
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;

        for (int i = 0; i < n; i++) {
            adj[i] = vector<int>{};
        }

        for (vector<int> edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            if (adj.find(i) != adj.end()) {
                res++;
                dfs(i, adj);
            }
        }

        return res;
    }
};

