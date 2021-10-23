// https://www.cnblogs.com/grandyang/p/7261663.html
// DP (top-down)

class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int n = price.size(), ans = 0;
        for(int i = 0; i < n; i++) 
            ans += price[i] * needs[i];
        
        for(auto offer : special) {
            bool isValid = true;
            for(int j = 0; j < n; j++) {
                if(needs[j] < offer[j]) isValid = false;
                needs[j] -= offer[j];
            }
            if(isValid)
                ans = min(ans, shoppingOffers(price, special, needs) + offer.back());
            for(int j = 0; j < n; j++)
                needs[j] += offer[j];
        }
        
        return ans;
    }
};
