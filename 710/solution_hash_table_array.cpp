// https://www.cnblogs.com/grandyang/p/10029772.html
// hash table + array

class Solution {
public:
    Solution(int n, vector<int>& blacklist) {
        len = n - blacklist.size();
        unordered_set<int> st;
        for(int i = len; i < n; i++) st.insert(i);
        for(int num : blacklist) st.erase(num);
        auto it = st.begin();
        for(int num : blacklist)
            if(num < len) m[num] = *it++;
    }
    
    int pick() {
        int idx = rand() % len;
        return m.count(idx) ? m[idx] : idx;
    }
    
private:
    unordered_map<int, int> m;
    int len;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */
