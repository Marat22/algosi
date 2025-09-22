// https://leetcode.com/problems/pacific-atlantic-water-flow/

#include<stdbool.h>
#include<stdlib.h>

int rows, cols;
bool pacificVisited[201][201], atlanticVisited[201][201];

void updateVisited(
    int** heights,
    bool visited[201][201],
    int r,
    int c,
    int prevHeight
) {
    if (r < 0 || c < 0 || r >= rows || c >= cols
        || visited[r][c]
        || heights[r][c] < prevHeight) {
        return;
    }

    visited[r][c] = true;
    updateVisited(heights, visited, r+1, c, heights[r][c]);
    updateVisited(heights, visited, r-1, c, heights[r][c]);
    updateVisited(heights, visited, r, c+1, heights[r][c]);
    updateVisited(heights, visited, r, c-1, heights[r][c]);
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** pacificAtlantic(int** heights, int heightsSize, int* heightsColSize, int* returnSize, int** returnColumnSizes) {
    rows = heightsSize;
    cols = *heightsColSize;

    memset(pacificVisited, 0, sizeof(pacificVisited));
    
    memset(atlanticVisited, 0, sizeof(atlanticVisited));
    for (int c = 0; c < cols; c++) {
        updateVisited(
            heights,
            pacificVisited,
            0,
            c,
            heights[0][c]
            );
        updateVisited(
            heights,
            atlanticVisited,
            rows-1,
            c,
            heights[rows-1][c]
            );
    }

    for (int r = 0; r < rows; r++) {
        updateVisited(
            heights,
            pacificVisited,
            r,
            0,
            heights[r][0]
            );
        updateVisited(
            heights,
            atlanticVisited,
            r,
            cols-1,
            heights[r][cols-1]
            );
    }

    *returnSize = 0;
    int **res = NULL;

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (atlanticVisited[r][c] == true && pacificVisited[r][c] == true) {
                (*returnSize)++;
                res = realloc(res, (*returnSize) * sizeof(int*));
                res[*returnSize-1] = malloc(2 * sizeof(int));
                res[*returnSize-1][0] = r;
                res[*returnSize-1][1] = c;
            
                (*returnColumnSizes) = realloc((*returnColumnSizes), (*returnSize) * sizeof(int));
                (*returnColumnSizes)[*returnSize-1] = 2; 
            }
        }
    }

    return res;
}
