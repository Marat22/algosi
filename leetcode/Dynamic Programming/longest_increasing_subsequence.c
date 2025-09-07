// https://leetcode.com/problems/longest-increasing-subsequence/

#define MAX(a,b) ((a) > (b) ? (a) : (b))

unsigned int get_inx(int inx) {
    return inx + 10000;
}

int lengthOfLIS(int* nums, int numsSize) {
    // solution is based on this video - https://www.youtube.com/watch?v=cjWnW0hdF1Y

    int LIS[numsSize];

    for (int i = 0; i < numsSize; i++) {
        LIS[i] = 1;
    }

    int best = -20000;
    for (int i = numsSize - 1; i >= 0; i--) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] < nums[j]) {
                LIS[i] = MAX(LIS[i], 1 + LIS[j]);
                best = MAX(best, LIS[i]);
            }
        }
    }

    if (best == -20000) {
        return 1;
    }
    return best;
}
