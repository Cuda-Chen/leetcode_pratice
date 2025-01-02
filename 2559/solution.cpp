class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        unordered_set<char> m{'a', 'e', 'i', 'o', 'u'};
        int n = words.size();
        vector<int> pre(n); // prefix sum of criterim
        for(int i = 0; i < n; i++) {
            string w = words[i];
            pre[i] = (i - 1 < 0 ? 0 : pre[i - 1]);
            if(
                m.count(w.front()) &&
                m.count(w.back())
            )
                pre[i]++;
        }

        /*for(int e : pre)
            printf("%d ", e);
        puts("");*/

        int q = queries.size();
        vector<int> ans(q);
        for(int i = 0; i < q; i++) {
            int s = queries[i][0];
            int e = queries[i][1];
            ans[i] = pre[e] - (s - 1 >= 0 ? pre[s - 1] : 0);
        }
        return ans;
    }
};
