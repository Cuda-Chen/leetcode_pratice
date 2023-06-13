// https://walkccc.me/LeetCode/problems/0269/
// topological sort

class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, unordered_set<char>> g;
        vector<int> in(26);
        build(g, words, in);
        return topology(g, in);
    }

private:
    void build(unordered_map<char, unordered_set<char>> &g, const vector<string> &words, vector<int> &in) {
        // Create node for each character in each word
        for(auto w : words) {
            for(char c : w) {
                if(!g.count(c))
                    g[c] = unordered_set<char>();
            }
        }

        for(int i = 1; i < words.size(); i++) {
            const string &first = words[i - 1];
            const string &second = words[i];
            int len = min(first.size(), second.size());
            for(int j = 0; j < len; j++) {
                char u = first[j], v = second[j];
                if(u != v) {
                    if(!g[u].count(v)) {
                        g[u].insert(v);
                        ++in[v - 'a'];
                    }
                    break; // Later character's order are meaningless
                }

                // First = "ab", second = "a" -> invalid
                if(j == len - 1 && first.size() > second.size()) {
                    g.clear();
                    return;
                }
            }
        }
    }

    string topology(unordered_map<char, unordered_set<char>> &g, vector<int> &in) {
        string s;
        queue<char> q;

        for(auto &[c, _] : g) {
            if(in[c - 'a'] == 0)
                q.push(c);
        }

        while(!q.empty()) {
            char u = q.front();
            q.pop();
            s += u;
            for(char v : g[u]) {
                if(--in[v - 'a'] == 0)
                    q.push(v);
            }
        }

        // Words = ["z", "x", "y", "x"]
        return s.size() == g.size() ? s : "";
    }
};
