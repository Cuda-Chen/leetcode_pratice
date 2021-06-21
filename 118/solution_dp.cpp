// DP (bottom-up)
// Beats 62% memory usage of C++ submissions
// because not using vector pre-allocation.

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        
        for(int i = 0; i < numRows; i++) {
            vector<int> temp;
            
            if(i == 0) {
                ans.push_back({1});
            } else if(i == 1) {
                ans.push_back({1, 1});
            } else {
                temp.push_back(1); // front 
                
                for(int j = 1; j < i; j++)
                    temp.push_back(ans[i - 1][j - 1] + ans[i - 1][j]);
                
                temp.push_back(1); // rear
                
                ans.push_back(temp);
            }
        }
        
        return ans;
    }
};
