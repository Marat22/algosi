#include <string.h>
#include <stdio.h>

int removeElement(int* nums, int numsSize, int val) {
    if (numsSize == 0) return numsSize;
    int biggest_not_val = numsSize - 1, i = 0, finalSize = 0;

    while (nums[biggest_not_val] == val) {
        biggest_not_val--;
        if (biggest_not_val < 0)
            return 0;
    }

    for (; i <= biggest_not_val; i++) {
        if (nums[i] == val) {
            if (biggest_not_val == i) {
                printf("DIE1    , i=%d, ", i);
                return finalSize;
            }

            nums[i] ^= nums[biggest_not_val];
            nums[biggest_not_val] ^= nums[i];
            nums[i] ^= nums[biggest_not_val];
        

            while (nums[biggest_not_val] == val) {
                biggest_not_val--;
                finalSize = i + 1;
                printf("DIE1    , i=%d, ", i);
                if (biggest_not_val < 0)
                    return finalSize;
            }
        }
        finalSize = i + 1;
        printf("Regular add finalSize, i=%d, ", i);

    }
    printf("DIE3    , i=%d, ", i);
    return finalSize;
}

int main() {
    int nums[] = {1};
    removeElement(nums, 1, 1);
}
