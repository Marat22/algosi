// https://leetcode.com/problems/implement-trie-prefix-tree/description/

class Trie {
private:
    unordered_map<char, Trie*> Children;
    bool IsEnd = false;

public:
    Trie() {
        IsEnd=false;
    }
    
    void insert(string word) {
        int p = 0;
        Trie *cur = this;
        while (p < word.size()) {
            if ( cur->Children.find(word[p]) == cur->Children.end() ) {
                cur->Children[word[p]] = new Trie();
            }

            cur = (cur->Children[word[p]]);
            p++;
        }
        cur->IsEnd = true;
    }
    
    bool search(string word) {
        int p = 0;
        Trie *cur = this;
        while (p < word.size()) {
            if ( cur->Children.find(word[p]) == cur->Children.end() ) {
                return false;
            }

            cur = (cur->Children[word[p]]);
            p++;
        }
        return cur->IsEnd;
        // return cur->EndsOfWords.contains(word[word.size()-1]);
    }
    
    bool startsWith(string prefix) {
        int p = 0;
        Trie *cur = this;
        while (p < prefix.size()) {
            if ( cur->Children.find(prefix[p]) == cur->Children.end() ) {
                return false;
            }

            cur = (cur->Children[prefix[p]]);
            p++;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */