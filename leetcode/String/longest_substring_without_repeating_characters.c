// https://leetcode.com/problems/longest-substring-without-repeating-characters/

#define MAX(a,b) (a) > (b) ? (a) : (b)

int lengthOfLongestSubstring(char* s) {
    int chars[128], maxLen = 0, left = 0, s_right;
    for (int i = 0; i < 128; i ++) {
        chars[i] = -1;
    }

    for (int right = 0; right < strlen(s); right++) {
        s_right = s[right];
        if (chars[s_right] >= left) { // if s_right is present in current word, then we need to update left
            left = chars[s_right] + 1;
        }
        maxLen = MAX(maxLen, right - left + 1);
        chars[s_right] = right;
    }

    return maxLen;
}