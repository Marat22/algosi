class Solution {
public:
    int getSum(int a, int b) {
        while ((a & b) != 0) {
            int tmp = a ^ b;
            b = (a & b) << 1;
            a = tmp;
        }
        return a | b;
    }
};