// trie
// trie implementation adopt from: https://walkccc.me/LeetCode/problems/3042/

struct TrieNode {
    unordered_map<char, shared_ptr<TrieNode>> c;
    int cnt = 0;
};

class Trie {
public:
    void insert(const string &w) {
        int cnt = 0;
        shared_ptr<TrieNode> n = root;
        for(char j : w) {
            if(!n->c[j])
                n->c[j] = make_shared<TrieNode>();
            n = n->c[j];
            n->cnt++;
        }
    }

    int search(const string &w) {
        shared_ptr<TrieNode> n = root;
        if(!n->c[w[0]])
            return 0;
        n = n->c[w[0]];
        int ans = n->cnt;
        for(int i = 1; i < w.size(); i++) {
            if(!n->c[w[i]])
                return 0;
            n = n->c[w[i]];
            ans = min(ans, n->cnt);
        }
        return ans;
    }

private:
    shared_ptr<TrieNode> root = make_shared<TrieNode>();
};

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        Trie trie;

        for(string w : words)
            trie.insert(w);

        return trie.search(pref);
    }
};
