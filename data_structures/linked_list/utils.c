#include <limits.h>
#include "utils.h"

unsigned int get_number_len(int val) {
    unsigned int l = 1;
    if (val < 0) l++;

    val /= 10;
    while (val) {
        val /= 10;
        l++;
    }
    return l;
}

unsigned int get_max_number_len() {
    unsigned int MAX_NUMBER_LEN= get_number_len(INT_MAX);
    return MAX_NUMBER_LEN;
}
