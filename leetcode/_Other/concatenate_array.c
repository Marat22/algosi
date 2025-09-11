// https://leetcode.com/problems/concatenation-of-array/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getConcatenation(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize * 2;
    nums = realloc(nums, sizeof(int) * (*returnSize));

    memcpy(nums + numsSize, nums, sizeof(int) * numsSize);

    return nums;
}