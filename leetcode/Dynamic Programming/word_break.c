// https://leetcode.com/problems/word-break/

#include<stdbool.h>

bool wordBreak(char* s, char** wordDict, int wordDictSize) {
    // Top Down Solution
    
    bool dp[strlen(s)+1];

    memset(dp, false, sizeof(dp));

    dp[0] = true;

    for (int i = 0; i < strlen(s); i++) {
        if (dp[i]) {
            for (int j = 0; j < wordDictSize; j++) {
                if (
                    strlen(s + i) >= strlen(wordDict[j])
                    && strncmp(wordDict[j], s+i, strlen(wordDict[j])) == 0
                ) {
                    dp[i + strlen(wordDict[j])] = true;
                }
            }
        }
    }

    return dp[strlen(s)];
}