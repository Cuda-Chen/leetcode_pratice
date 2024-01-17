class Solution {
public:
    bool uniqueOccurrences(vector<int>& A) {
        if(A.size() == 1)
            return true;

        unordered_map<int, int> m;
        for(int a : A)
            m[a]++;

        unordered_set<int> seen;
        for(auto &[_, cnt] : m) {
            if(seen.count(cnt))
                return false;
            seen.insert(cnt);
        }
        return true;
    }
};
