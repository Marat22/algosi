// https://leetcode.com/problems/coin-change/

#include<stdlib.h>

#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))

int comp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int coinChange(int* coins, int coinsSize, int amount) {
    // USED THIS SOLUTION https://leetcode.com/problems/coin-change/solutions/1104361/coin-change-simple-dp-w-explanation-short-easy
    if (amount == 0) {
        return 0;
    }

    qsort(coins, coinsSize, sizeof(int), comp);
    
    int arr_len = 0;
    int *arr = NULL;

    for (int i = 0; i < coinsSize; i++) {
        if ( 
            (i == 0 
                || (i > 0 && coins[i] != coins[i-1])
            ) 
            && coins[i] <= amount
        ) {
            // if (i > 0) printf("coins[i]=%d coins[i-1]=%d\n", coins[i], coins[i-1]);
            arr_len++;
            arr = realloc(arr, sizeof(int) * arr_len);
            arr[arr_len-1] = coins[i];
        }
    }

    int dp[amount + 1];
    for (int i = 0; i <= amount; ++i) {
        dp[i] = amount + 1;
    }

    dp[0] = 0;

    for (int currAmount = 1; currAmount <= amount; currAmount++) {
        for (int coinInx = 0; coinInx < arr_len; coinInx++) {
            int coin = arr[coinInx];
            if (coin <= currAmount ) {
                // arr[currAmount];
                // arr[coinInx];
                // arr[currAmount - arr[coinInx]];
                dp[currAmount] = MIN(dp[currAmount], 1 + dp[currAmount - coin]
                    );
            }
        }
    }
    return dp[amount] > amount ? -1 : dp[amount];
}
