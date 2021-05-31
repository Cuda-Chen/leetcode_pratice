// naive (brute-force)

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> result;
        sort(products.begin(), products.end(), [](const string &a, const string &b) {
            if(a.compare(0, b.size(), b) == 0
               || b.compare(0, a.size(), a) == 0)
                return a.size() < b.size();
            else
                return a < b;
        });
        
        for(int i = 0; i < searchWord.size(); i++) {
            vector<string> temp;
            for(string product : products) {
                bool flag = true;
                for(int j = 0; j <= i; j++) {
                    if(product[j] != searchWord[j]) {
                        flag = false;
                        break;
                    }
                }
                
                if(flag && temp.size() < 3) {
                    temp.push_back(product);
                }
            }
            
            result.push_back(temp);
        }
        
        return result;
    }
};
