// https://contest.yandex.ru/contest/80940/problems/I/

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int longest_consecutive_path(int n, int m, const vector<vector<int>>& grid) {
    vector<vector<int>> dp(n, vector<int>(m, 0));
    int max_len = 0;
    const int directions_i[] = {0, 0, 1, -1};
    const int directions_j[] = {1, -1, 0, 0};
    function<int(int, int)> DFS = [&](int i, int j) -> int {
        if (dp[i][j] != 0) {
            return dp[i][j];
        }
        int curr_val = grid[i][j];
        int max_chain = 1;

        for (int dir = 0; dir < 4; ++dir) {
            int ni=i+directions_i[dir];
            int nj=j + directions_j[dir];
            if (ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] == curr_val + 1) {
                int neighbor_length = DFS(ni, nj);
                max_chain = max(max_chain, 1 + neighbor_length);
            }
        }

        dp[i][j] = max_chain;
        return max_chain;
    };

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (dp[i][j] == 0) {
                int current_max = DFS(i, j);
                max_len = max(max_len, current_max);
            }
        }
    }

    return max_len;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }

    int result = longest_consecutive_path(n, m, grid);
    cout << result << endl;

    return 0;
}
