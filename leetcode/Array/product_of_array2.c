// https://leetcode.com/problems/product-of-array-except-self/


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    // IT'S NOT MY SOLUTION, I JUST ADAPTED THIS PYTHON SOLUTION - https://leetcode.com/problems/product-of-array-except-self/solutions/5833007/video-looping-the-input-array-twice/comments/2757690/
    int *temp = malloc(sizeof(int) * numsSize), i = 1, left = 1, right = 1;
    *returnSize = numsSize; 

    for (i=0; i < numsSize; i++)
        temp[i] = 1;

    for (i =1;i < numsSize; i++) {
        // if (i <= (numsSize / 2 + numsSize % 2) - 1) temp[i] = 1;

        temp[i] *= left * nums[i-1];
        left *= nums[i-1];

        temp[numsSize - i - 1] *= right * nums[numsSize - i];
        right *= nums[numsSize - i];
    }

    return temp;
}