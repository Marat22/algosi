// https://leetcode.com/problems/word-break/description/

int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}


class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> reachable(s.size()+1, false);

        reachable[0] = true;

        for (int i = 0; i < s.size(); i++) {
            if (reachable[i]) {
                string substr = s.substr(i, s.size());
                for (int j = 0; j < wordDict.size(); j++) {
                    if (substr.rfind(wordDict[j], 0) == 0) { // startswith
                        reachable[i + wordDict[j].size()] = true;
                    }
                }
            }
        }
        return reachable[s.size()];

    }
};