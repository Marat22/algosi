// https://leetcode.com/problems/word-search/

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> path(6, vector<bool>(6, false));

        function<bool(int16_t, int16_t, int16_t)> dfs = [&](int16_t r, int16_t c, int16_t word_ind) -> bool
         {
            tuple<int16_t, int16_t> key = make_tuple(r,c);
            if (
                // if out of board
                r < 0 
                || r >= board.size() 
                || c < 0 
                || c >= board[0].size()
                // if not matches
                || board[r][c] != word[word_ind]
                // if already in path
                || path[r][c] 
                ) {
                return false;
            }

            if (word_ind == word.size()-1) {
                return true;
            }

            // path.insert(key);
            path[r][c] = true;
            if (dfs(r+1, c, word_ind+1)) {
                return true;
            }
            if (dfs(r-1, c, word_ind+1)) {
                return true;
            }
            if (dfs(r, c+1, word_ind+1)) {
                return true;
            }
            if (dfs(r, c-1, word_ind+1)) {
                return true;
            }

            path[r][c] = false;
            return false;
        };

        for (int row = 0; row < board.size(); row++) {
            for (int col = 0; col < board[0].size(); col++) {
                if (dfs(row, col, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};