class Solution {
public:
    int largestAltitude(vector<int>& A) {
        int ans = 0;
        int tmp = 0;
        for(int &a : A) {
            tmp += a;
            ans = max(ans, tmp);
        }
        return ans;
    }
};
