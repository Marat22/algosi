// https://leetcode.com/problems/plus-one/

#include<string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int* res;
    res = malloc(sizeof(int) * digitsSize);
    *returnSize = digitsSize;
    memcpy(res, digits, sizeof(int) * digitsSize);
    if (digits[digitsSize-1] != 9) {
        res[digitsSize-1] = res[digitsSize-1] + 1;
        *returnSize = digitsSize;
        return res;
    }
    else {
        // int left = 1;
        for (int i = digitsSize - 1; i >= 0; i--) {
            res[i] = res[i] + 1;
            if (res[i] > 9) {
                res[i] = 9;
                // left = 1;
            }
            else {
                // left = 0;
                return res;
            }
        }
        (*returnSize)++;
        free(res);
        res = calloc(digitsSize + 1, sizeof(int));
        res[0] = 1;
        return res;
    }
}
