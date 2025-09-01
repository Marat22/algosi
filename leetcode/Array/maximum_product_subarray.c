// https://leetcode.com/problems/maximum-product-subarray/

#include<stdio.h>
#include<stdbool.h>
#include<limits.h>

#define max(a,b) ((a) > (b) ? (a) : (b))


#define OR1(VAL) ( (VAL) == 0 ? 1 : VAL )
int maxProduct(int* nums, int numsSize) {
    if (numsSize == 1) {
        return nums[0];
    }

    int best = INT_MIN;
    int reversed[numsSize];

    for (int i = 0; i < numsSize; i++) {
        reversed[numsSize - i - 1] = nums[i];
    }
    best = max(reversed[0], best);
    best = max(nums[0], best);

    for (int i = 1; i < numsSize; i++) {
        reversed[i] *= OR1(reversed[i-1]);
        nums[i] *= OR1(nums[i-1]);
        best = max(reversed[i], best);
        best = max(nums[i], best);
    }

    return best;
}
