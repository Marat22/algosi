// https://leetcode.com/problems/search-insert-position/
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

#define DEBUG

#ifdef DEBUG
int max_it = 0;
#endif

int searchInsert(int* nums, int numsSize, int target) {
    
    if (nums[0] >= target) {
        return 0;
    }
    if (nums[numsSize-1] < target) {
        return numsSize;
    }

    int low = 0, high = numsSize, result = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target) {
            return mid;
        }
        if (target < nums[mid]) {
            result = mid;
            high = mid - 1;
        }
        else {
            result = mid + 1;
            low = mid + 1;
        }

    }


    return result;
    // int inx = numsSize / 2;


        // int mid;
        // while (low <= high) {
        //     mid = low + (high - low) / 2;
        //     if (nums[mid] <= target) {
        //         result = mid;
        //         low = mid + 1;
        //     }
        //     else {
        //         high = mid - 1;
        //     }
        // }
    // return result;
// 
}

int main() {
    int nums[4] = {1,3,5,6};
    printf("%d\n", searchInsert(nums, 4, 7));
}
