// O(n) time 

class Solution {
public:
    int buyChoco(vector<int>& A, int money) {
        int min1 = INT_MAX, min2 = INT_MAX;
        for(int a : A) {
            if(a < min1) {
                min2 = min1;
                min1 = a;
            } else if(a < min2) {
                min2 = a;
            }
        }
        int ans = money - (min1 + min2);
        return ans < 0
            ? money
            : ans;
    }
};
