class Solution {
public:
    int minElement(vector<int>& A) {
        int ans = INT_MAX;
        for(int a : A) {
            int sum = 0;
            while(a) {
                sum += a % 10;
                a /= 10;
            }
            ans = min(ans, sum);
        }
        return ans;
    }
};
