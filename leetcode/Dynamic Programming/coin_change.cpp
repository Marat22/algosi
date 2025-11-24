// https://leetcode.com/problems/coin-change/description/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) {return 0;}
        vector<int> best_qty(amount+1, amount+1);

        best_qty[0] = 0;

        for (int cur_amount = 1; cur_amount <= amount; cur_amount++) {
            for (int coin: coins) {
                if (coin <= cur_amount) {
                    best_qty[cur_amount] = min(best_qty[cur_amount], best_qty[cur_amount-coin] + 1);
                    // continue;
                }
            }
        }
        return best_qty[amount] > amount ? -1 : best_qty[amount];
    }
};