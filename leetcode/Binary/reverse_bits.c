// https://leetcode.com/problems/reverse-bits/

int reverseBits(int n) {
    int res = 0;
    for (int i = 1; i <= 32; i++) {
        if ((int)(pow(2, i)) & n) {
            res |= 1 << (32 - i - 1);
        }
    }
    return res;
}