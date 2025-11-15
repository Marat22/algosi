// https://leetcode.com/problems/palindromic-substrings/

class Solution {
public:
    int countSubstrings(string s) {
        int left = 0, right1 = 1, total = 0;
        
        auto update_total_number = [&](int l, int r, int& tot) -> void {
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                tot++;
                l--;
                r++;
            }
        };
        
        while (left <= s.size() - 1) {
            update_total_number(left, left, total);
            update_total_number(left, right1, total);
            left++;
            right1++;
        }

        return total;
    }
};
