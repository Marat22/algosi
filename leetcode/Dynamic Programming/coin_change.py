# https://leetcode.com/problems/coin-change/

class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        if amount == 0:
            return 0
        coins.sort()

        DF = [0] * (amount + 1)
        
        for current_amount in range(1, amount + 1): # 5
            best_val = float("+inf")
            for coin in coins: # 1
                if coin > current_amount:
                    break
                elif coin == current_amount:
                    best_val = 1
                    break
                else:
                    best_val = min(best_val, DF[current_amount - coin] + 1)
            DF[current_amount] = best_val
        if DF[amount] == 0 or DF[amount] == float('inf'):
            return -1
        return DF[amount]
