// https://leetcode.com/problems/number-of-islands/

void dfs(
    char** grid,
    const int r,
    const int c,
    const int ROWS,
    const int COLS
) {
    if (
        r != -1 && r != ROWS && c != -1 && c != COLS
        && grid[r][c] == '1'
    ) {
        grid[r][c] = '0';

        dfs(grid, r+1, c, ROWS, COLS);
        dfs(grid, r-1, c, ROWS, COLS);
        dfs(grid, r, c+1, ROWS, COLS);
        dfs(grid, r, c-1, ROWS, COLS);
    }

}

int numIslands(char** grid, int gridSize, int* gridColSize) {
    const int ROWS = gridSize, COLS = *gridColSize;

    int res = 0, r, c;

    for (r = 0; r < ROWS; r++) {
        for (c = 0; c < COLS; c++) {
            if (grid[r][c] == '1') {
                dfs(grid, r, c, ROWS, COLS);
                res++;
            } 
        }
    }

    return res;
}
