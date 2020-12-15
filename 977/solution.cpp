// naive

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result = nums;
        for(int i = 0; i < result.size(); i++) {
            result[i] = result[i] * result[i];
        }
        sort(result.begin(), result.end());
        return result;
    }
};
