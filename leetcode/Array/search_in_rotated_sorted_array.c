// https://leetcode.com/problems/search-in-rotated-sorted-array/

#include<stdbool.h>

int search(int* nums, int numsSize, int target) {
    if (numsSize == 1) {
        if (nums[0] == target) return 0;
        else return -1;
    }
    bool rotated = true;
    if (nums[0] < nums[numsSize-1]) {
        rotated = false;
    }
    int low = 0;
    int high = numsSize - 1;
    int last_val = nums[numsSize - 1];
    int first_val = nums[0];

    int mid;
    while (low <= high) {
        mid = low + (high - low) / 2;

        if (nums[mid] == target) {
            return mid;
        }

        if (rotated) {
            if (target >= first_val && nums[mid] < first_val) {
                high = mid - 1;
                continue;
            }
            else if (target <= last_val && nums[mid] > last_val) {
                low = mid + 1;
                continue;
            }
        }
 
        if (target > nums[mid]) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1;
}
