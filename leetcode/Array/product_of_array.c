// https://leetcode.com/problems/product-of-array-except-self/


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int* temp = malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;

    int for_economy = 0, i = 1, hz;

    temp[0] = 1;
    for (i = 1; i < numsSize; i++) {
        temp[i] = temp[i-1] * nums[i-1];
        if (nums[i-1] == 0) for_economy++;
    }

    if (for_economy > 1) {
        free(temp);
        return calloc(numsSize, sizeof(int));
    }

    for_economy = 1; // use same variable for economical memory usage (sorry)
    for (i = numsSize - 1; i >= 0; i--) {
        hz = nums[i];
        nums[i] = for_economy * temp[i];
        for_economy *= hz;
    }

    return nums;
}   