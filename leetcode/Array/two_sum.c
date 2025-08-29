// https://leetcode.com/problems/two-sum/

typedef struct {
    int key;
    int value;
    UT_hash_handle hh;
} IntIntHash;

void addItem(IntIntHash **hash_table, int key, int value) {
    IntIntHash *item = (IntIntHash *)malloc(sizeof(IntIntHash));
    item->key = key;
    item->value = value;
    HASH_ADD_INT(*hash_table, key, item);
}

IntIntHash *findItem(IntIntHash **hash_table, int key) {
    IntIntHash *item;
    HASH_FIND_INT(*hash_table, &key, item);
    return item;
}


int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    IntIntHash *hash_table = NULL;
    for (int i = 0; i < numsSize; i++) {
        IntIntHash *item = findItem(&hash_table, target - nums[i]);
        if (item) {
            int* res = malloc(sizeof(int) * 2);
            res[0] = item->value;
            res[1] = i;
            *returnSize = 2;
            return res;
        }
        addItem(&hash_table, nums[i], i);
    }
    *returnSize = 0;
    int* res = malloc(sizeof(int) * 0);
    return res;
}
