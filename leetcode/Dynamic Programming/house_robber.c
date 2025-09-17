// https://leetcode.com/problems/house-robber/

#define MAX(a,b) (a) > (b) ? (a) : (b)

int rob(int* nums, int numsSize) {
    int* res = malloc(sizeof(int) * (numsSize + 2));

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
