// Scan the array, divide odd and even number, then merge odd and even arrays

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> odd;
        vector<int> even;
        for(auto value : A) {
            if(value % 2 == 0) {
                even.push_back(value);
            } else {
                odd.push_back(value);
            }
        }
        vector<int> result;
        result.reserve(odd.size() + even.size());
        result.insert(result.end(), even.begin(), even.end());
        result.insert(result.end(), odd.begin(), odd.end());
        return result;
    }
};
