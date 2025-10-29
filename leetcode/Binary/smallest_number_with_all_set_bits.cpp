// https://leetcode.com/problems/smallest-number-with-all-set-bits/

class Solution {
public:
    int smallestNumber(int n) {
        int x = 1;
        for (int i = 0; i < 32; i++) {
            if (x >= n) {
                return x;
            }
            x = x << 1;
            x |= 1;
        }
        return x;
    }
};