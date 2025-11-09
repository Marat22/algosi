// https://leetcode.com/problems/longest-substring-without-repeating-characters/


void print_set(unordered_set<char> s) {
    for (auto x : s) 
        cout << x << " ";
    cout << endl;
}

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> symbols;
        string cur_s = "";

        int max_len = 0;

        for (int i = 0; i < s.size(); i++) {
            if (symbols.contains(s[i])) {
                max_len = max(max_len, (int)cur_s.size());

                int sz = cur_s.size();
                for (int j = 0; j < sz; j++) {
                    char to_erase = cur_s[0];
                    cur_s.erase(cur_s.begin());
                    symbols.erase(to_erase);
                    if (to_erase == s[i]) {
                        break;
                    }
                }
            }
            symbols.insert(s[i]);
            cur_s += s[i];
        
        }

        max_len = max(max_len, (int)cur_s.size());

        return max_len;
    }
};