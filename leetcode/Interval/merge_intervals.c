// https://leetcode.com/problems/merge-intervals/

#define MAX(a,b) (a) > (b) ? (a) : (b)

int compare(const void *a, const void *b) {
    int *intervalA = *(int **)a;
    int *intervalB = *(int **)b;
    return intervalA[0] - intervalB[0];
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
    qsort(intervals, intervalsSize, sizeof(int*), compare);

    *returnSize = 0;
    int** res = malloc(sizeof(int*) * intervalsSize);
    (*returnColumnSizes) = realloc((*returnColumnSizes), intervalsSize * sizeof(int));
    int currentStart = intervals[0][0];
    int currentEnd = intervals[0][1];

    for (int i = 0; i < intervalsSize; i++) {
        if (intervals[i][0] <= currentEnd) {
            currentEnd = MAX(intervals[i][1], currentEnd);
        }
        else {
            (*returnSize)++;
            // res = realloc(res, sizeof(int*) * (*returnSize));
            res[*returnSize-1] = malloc(sizeof(int) * 2);
            res[*returnSize-1][0] = currentStart;
            res[*returnSize-1][1] = currentEnd;
            // (*returnColumnSizes) = realloc((*returnColumnSizes), (*returnSize) * sizeof(int));
            (*returnColumnSizes)[*returnSize-1] = 2; 
            currentStart = intervals[i][0];
            currentEnd = intervals[i][1];
        }
    }


    (*returnSize)++;
    res = realloc(res, sizeof(int*) * (*returnSize));
    res[*returnSize-1] = malloc(sizeof(int) * 2);
    res[*returnSize-1][0] = currentStart;
    res[*returnSize-1][1] = currentEnd;
    (*returnColumnSizes) = realloc((*returnColumnSizes), (*returnSize) * sizeof(int));
    (*returnColumnSizes)[*returnSize-1] = 2; 

    return res;
}
