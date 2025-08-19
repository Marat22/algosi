// https://leetcode.com/problems/climbing-stairs/

int climbStairs(int n) {
    if (n < 3) {
        return n;
    }

    int res = 0, prev_prev = 1, prev = 2, i = 0;

    for (i = 3; i <= n; i++) {
        // printf("%d", i);
        res = prev + prev_prev;
        prev_prev = prev;
        prev = res;
    }

    return res;
}