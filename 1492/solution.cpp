// naive

class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> result;
        for(int i = 1; i <= n; i++) {
            if(n % i == 0)
                result.push_back(i);
        }
        
        return (k > result.size()) ? -1 : result[k - 1];
    }
};
