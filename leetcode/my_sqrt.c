#include<stdio.h>
#include<math.h>

int mySqrt(int x) {
    if (x == 0) return 0;
    if (x == 1) return 1;
    int min = 0;
    int max = x;
    int mid;
    int result;
    while (min <= max)
        {
            mid = min + (max - min) / 2;
            if (mid == x / mid) {
                return mid;
            }
            else if (mid > x / mid) {
                max = mid - 1;
                result = mid - 1;
            }
            else if (mid < x / mid) {
                min = mid + 1;
                result = mid ;
            }
        }
    return result;
}

int main() {
    printf("%d\n", mySqrt(1));
}
