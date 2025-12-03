// https://leetcode.com/problems/design-add-and-search-words-data-structure/description/

class WordDictionary {
private:
    WordDictionary* children[26];
    bool isEnd;
public:
    WordDictionary() {
        memset(children, 0, sizeof(children));
        isEnd = false;
    }

    void addWord(string word) {
        WordDictionary* cur = this;
        for (char c : word) {
            int idx = c - 'a';
            if (!cur->children[idx])
                cur->children[idx] = new WordDictionary();
            cur = cur->children[idx];
        }
        cur->isEnd = true;
    }

    bool search(string word) {
        WordDictionary* cur = this;
        for (size_t i = 0; i < word.size(); i++) {
            char c = word[i];
            if (c == '.') {
                string Wsubstr = word.substr(i+1, word.length() - i - 1);
                for (int z = 0; z < 26; z++) {
                    if (cur->children[z] && cur->children[z]->search(Wsubstr)) {
                        return true;
                    }
                }
                return false;
            }
            int idx = c - 'a';
            if (!cur->children[idx])
                return false;
            cur = cur->children[idx];
        }
        return cur->isEnd;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */