// https://leetcode.com/problems/longest-repeating-character-replacement/

int calc_best(char letter, string word, int k) {
        int left = 0;
        int right = 0;
        int best_len = 0;

        while (right < word.size()) {
            if (word[right] != letter) {
                k--;
            }
            if (k < 0) {
                if (word[left] != letter) {
                    k++;
                }
                left++;
            }

            best_len = max(best_len, right - left + 1);
            right++;
        }

        return best_len;
    }

class Solution {
public:
    
    int characterReplacement(string s, int k) {
        unordered_set<char> all_chars(s.begin(), s.end());

        int res = 0;
        for (auto it = all_chars.begin(); it != all_chars.end(); it++) {
            res = max(res, calc_best(*it, s, k));
        }

        return res;
    }
};