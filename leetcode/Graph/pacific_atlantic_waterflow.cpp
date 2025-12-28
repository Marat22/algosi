// https://leetcode.com/problems/pacific-atlantic-water-flow/

class Solution {
private:
    void explore(
        const vector<vector<int>>& heights,
        vector<vector<bool>>& explored,
        const int r,
        const int c,
        const int prev
    ) {
        if (r < 0 or c < 0 or r >= heights.size() or c >= heights[0].size()) {
            return;
        }

        if (explored[r][c] != false) {
            return;
        }

        if (heights[r][c] < prev) {
            return;
        }

        explored[r][c] = true;

        explore(heights, explored, r+1, c, heights[r][c]);
        explore(heights, explored, r, c+1, heights[r][c]);
        explore(heights, explored, r-1, c, heights[r][c]);
        explore(heights, explored, r, c-1, heights[r][c]);
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> explored_pacific (m, vector<bool> (n, false) );
        vector<vector<bool>> explored_atlantic (m, vector<bool> (n, false) );

        int r;
        int c;
        for (c = 0, r = 0; c < heights[0].size(); c++) {
            explore(heights, explored_pacific, r, c, -1);
        }
        for (c = 0, r = 0; r < heights.size(); r++) {
            explore(heights, explored_pacific, r, c, -1);
        }

        for (c = 0, r = heights.size()-1; c < heights[0].size(); c++) {
            explore(heights, explored_atlantic, r, c, -1);
        }
        for (c = heights[0].size()-1, r = 0; r < heights.size(); r++) {
            explore(heights, explored_atlantic, r, c, -1);
        }

        vector<vector<int>> res;

        for (r = 0; r < heights.size(); r++) {
            for (c = 0; c < heights[0].size(); c++) { 
                if (
                    explored_atlantic[r][c] == 1
                    and explored_atlantic[r][c] == explored_pacific[r][c]
                ) { 
                    res.insert(res.end(), {r,c});
                }
            }
        }

        return res;
    }
};