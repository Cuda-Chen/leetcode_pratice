class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int> m; // {char, cnt}
        for(char c : word)
            m[c]++;

        priority_queue<pair<int, char>> q;
        for(auto &[k, v] : m) {
            q.push({v, k});
        }

        int ans = 0;
        int cnt = 8; // key count
        int base = 1;
        while(!q.empty()) {
            if(cnt == 0) {
                base++;
                cnt = 8;
            }

            auto [k, _] = q.top();
            q.pop();
            ans += (k * base);

            //printf("%c %d %d %d\n", _, k, base, cnt);

            cnt--;
        }
        return ans;
    }
};
