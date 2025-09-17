// https://leetcode.com/problems/house-robber-ii/

#define MAX(a,b) (a) > (b) ? (a) : (b)

int rob1(int* nums, int numsSize) {
    int res[numsSize + 2];

    memcpy(res, nums, sizeof(int) * numsSize);
    res[numsSize] = 0;
    res[numsSize+1] = 0;

    for (int i = 2; i < numsSize + 2; i++) {
        if (i == 2) {
            res[i] += res[i-2];
            continue;
        }
        res[i] += MAX(res[i-2], res[i-3]);
    }

    return res[numsSize+1];
}


int rob(int* nums, int numsSize) {
    if (numsSize == 1) {
        return nums[0];
    }

    int res = rob1(nums + 1, numsSize - 1);
    nums[numsSize-1] = 0;
    res = MAX(res, rob1(nums, numsSize));

    return res;
}