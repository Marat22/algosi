# https://leetcode.com/problems/power-of-four/

class Solution:
    def isPowerOfFour(self, n: int) -> bool:
        a = bin(n)[2:]
        if a[0] != '1' or len(a[1:]) % 2 != 0:
            return False
        for i in range(1, len(a)):
            if a[i] != '0':
                return False
        return True
