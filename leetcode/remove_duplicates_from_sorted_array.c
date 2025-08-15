#include<stdio.h>


void get_next(int* nums, int* cursor, int* numsSize) {
    for (; *cursor < *numsSize; (*cursor)++) {
        if (*cursor == 0 || nums[*cursor] != nums[(*cursor)-1]) {
            return;
        }
    }
    *cursor = -1;
}

int removeDuplicates(int* nums, int numsSize) {
    if (numsSize <= 1) return numsSize;
    

    int cursor = 0;
    for (int i = 0; i <= numsSize; i++) {
        if (i == numsSize) return i;

        get_next(nums, &cursor, &numsSize);
        if (cursor == -1) {
            return i;
        }
        nums[i] = nums[cursor];
        cursor++;
    }
    
    
}

int main() {
    // int arr[10] = {0,0,1,1,1,2,2,3,3,4};
    // int k = removeDuplicates(arr, 10);

    int arr[7] = {1,1,3,3,3,4,4};
    // printf("%d\n", get_next(arr, 3, 7));
    int k = removeDuplicates(arr, 7);
    printf("{");
    for (int i = 0; i < k; i++) {
        printf("%d", arr[i]);
        if (i != k - 1) {
            printf(", ");
        }
    }
    printf("}\n");
}
