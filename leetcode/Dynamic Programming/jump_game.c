// https://leetcode.com/problems/jump-game/

#include<stdbool.h>

int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

bool canJump(int* nums, int numsSize) {
    if (numsSize == 1) {
        return true;
    }

    int max_inx = 0;
    for (int i = 0; i < numsSize; i++) {
        if (i > max_inx) {
            return false;
        }
        max_inx = max(max_inx, i + nums[i]);

    }

    return true;
}
