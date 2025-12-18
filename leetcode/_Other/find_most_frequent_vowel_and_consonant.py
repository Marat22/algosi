# https://leetcode.com/problems/find-most-frequent-vowel-and-consonant/

from collections import Counter

class Solution:
    def maxFreqSum(self, s: str) -> int:
        counter = Counter(s)
        vowels = set('aeiou')

        best_vowel = 0
        best_consonant = 0

        for c, num in counter.items():
            if c in vowels:
                best_vowel = max(best_vowel, num)
            else:
                best_consonant = max(best_consonant, num)
        return best_consonant + best_vowel 
