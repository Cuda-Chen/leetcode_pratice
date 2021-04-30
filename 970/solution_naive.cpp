// naive

class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> result {};
        if(bound <= 1) return result; // edge case 0
        
        if(x == 1 && y == 1) { // edge case 1
           result.push_back(2); 
        } else if(x == 1) { // edge case 2
            for(int j = 0; pow(y, j) <= bound; j++) {
                int temp = pow(y, j) + 1;
                if(temp <= bound) result.push_back(temp);
            }
        } else if(y == 1) { // edge case 3
            for(int i = 0; pow(x, i) <= bound; i++) {
                int temp = pow(x, i) + 1;
                if(temp <= bound) result.push_back(temp);
            }
        } else {
            for(int i = 0; pow(x, i) <= bound; i++) {
                for(int j = 0; pow(y, j) <= bound; j++) {
                    int temp = pow(x, i) + pow(y, j);
                    if(temp <= bound) result.push_back(temp);
                }
            }
        }
        
        // sort and remove duplicate elements
        sort(result.begin(), result.end());
        result.erase(unique(result.begin(), result.end()), result.end());
        
        return result;
    }
};
