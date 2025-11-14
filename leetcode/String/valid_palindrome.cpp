// https://leetcode.com/problems/valid-palindrome/

class Solution {
public:
    bool isPalindrome(string s) {
        // convert uppercase into lowercase
        // remove all non-alphanumeric characters (numbers - 48-57, uppercase chars - 65-90, lowercase chars - 97-122)
        
        int left = 0;
        int right = s.size();
        while (left < right) {
            if (!isalnum(s[left])) {
                left++;
            }
            else if (!isalnum(s[right])) {
                right--;
            }
            else {
                if (tolower(s[left]) != tolower(s[right])) {
                    return false;
                }
                left++;
                right--;
            }
        }
        return true;
    }
};
