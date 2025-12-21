// https://leetcode.com/problems/longest-common-subsequence/    

#define MAX(a,b) ((a) > (b) ? (a) : (b))

int longestCommonSubsequence(char* text1, char* text2) {
    int dp[strlen(text2)];
    memset(dp, 0, strlen(text2)*sizeof(int));

    int res = 0;

    for (size_t i = 0; i < strlen(text1); i++) {
        int max_pre = 0;
        for (size_t j = 0; j < strlen(text2); j++) {
            if (dp[j] < max_pre + 1 && text2[j] == text1[i]) {
                dp[j] = max_pre + 1;
                res = MAX(res, dp[j]);
            }
            else {
                max_pre = MAX(max_pre, dp[j]);
            }
        }
    }


    return res;
}