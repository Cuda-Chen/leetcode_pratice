class Solution {
public:
    long long findScore(vector<int>& A) {
        using Pair = std::pair<int, int>; // {num, idx}

        int n = A.size();
        priority_queue<Pair, vector<Pair>, std::greater<Pair>> q;
        for(int i = 0; i < n; i++)
            q.push({A[i], i});

        long long ans = 0LL;
        unordered_set<int> m; // marked indices
        while(!q.empty()) {
            auto [v, idx] = q.top();
            q.pop();
            printf("%d %d\n", v, idx);
            if(m.count(idx))
                continue;

            ans += v;
            m.insert(idx);
            if(idx - 1 >= 0)
                m.insert(idx - 1);
            if(idx + 1 < n)
                m.insert(idx + 1);
        }
        return ans;
    }
};
