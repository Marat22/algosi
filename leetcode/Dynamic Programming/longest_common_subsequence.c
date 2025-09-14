// https://leetcode.com/problems/longest-common-subsequence/

#define MAX(a,b) ((a) > (b)) ? a : b

int longestCommonSubsequence(char* text1, char* text2) {
    // used this video https://youtu.be/Ua0GhsJSlWM?si=FhBhPQbNKOw4Iu1Z to solve the problem

    int dp[strlen(text1)+1][strlen(text2)+1], row, col;
    memset(dp, 0, sizeof(dp));

    for (row = strlen(text1) - 1; row >= 0; row--) {
        for (col = strlen(text2) - 1; col >= 0; col--) {
            if (text1[row] == text2[col]) {
                dp[row][col] = 1 + dp[row+1][col+1];
            }
            else {
                dp[row][col] = MAX(dp[row+1][col], dp[row][col+1]);
            }
        }
    }
    return dp[0][0];
}