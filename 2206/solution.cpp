class Solution {
public:
    bool divideArray(vector<int>& A) {
        int n = A.size();
        if(n & 1)
            return false;

        unordered_map<int, int> m;
        for(int a : A) {
            m[a]++;
        }
        for(auto [_, v] : m) {
            if(v & 1)
                return false;
        }
        return true;
    }
};
