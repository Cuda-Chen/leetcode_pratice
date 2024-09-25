class TrieNode {
public:
    TrieNode() : cnt(0), child(26, nullptr) {}

    int cnt;
    vector<TrieNode *> child;
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        TrieNode *root = new TrieNode();
        for(string &w : words) {
            TrieNode *cur = root;
            for(char c : w) {
                int idx = c - 'a';
                if(!cur->child[idx])
                    cur->child[idx] = new TrieNode();
                cur = cur->child[idx];
                cur->cnt++;
            }
        }

        vector<int> ans;
        for(string &w : words) {
            TrieNode *cur = root;
            int tmp = 0;
            for(char c : w) {
                cur = cur->child[c - 'a'];
                tmp += cur->cnt;
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};
