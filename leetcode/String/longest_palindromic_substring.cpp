// https://leetcode.com/problems/longest-palindromic-substring/

class Solution {
public:
    string longestPalindrome(string s) {
        int max_len = 0, res_left, res_right;

        auto update_max_len = [&](int l, int r) -> void {
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                int cur_len = r - l + 1;
                if (cur_len > max_len) {
                    res_left = l;
                    res_right = r;
                    max_len = cur_len;
                }
                r++;
                l--;
            }
        };

        for (int left = 0; left < s.size(); left++) {
            update_max_len(left, left);
            update_max_len(left, left+1);
        }

        return s.substr(res_left, max_len);

    }
};