class Solution {
public:
    int findNumbers(vector<int>& A) {
        int ans = 0;
        for(int a : A) {
            int cnt = 0;
            while(a) {
                cnt++;
                a /= 10;
            }
            if(cnt % 2 == 0)
                ans++;
        }
        return ans;
    }
};
