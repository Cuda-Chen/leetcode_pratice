class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<vector<string>> m(4); // "electronics", "grocery", "pharmacy", "restaurant"
        int n = code.size();
        for(int i = 0; i < n; i++) {
            if(!isActive[i])
                continue;

            string c = code[i];
            if(!all_valid_chars(c))
                continue;

            string b = businessLine[i];
            if(b == "electronics")
                m[0].push_back(c);
            else if(b == "grocery")
                m[1].push_back(c);
            else if(b == "pharmacy")
                m[2].push_back(c);
            else if(b == "restaurant")
                m[3].push_back(c);
        }

        for(auto &v : m)
            ranges::sort(v);

        vector<string> ans;
        for(auto v : m)
            ans.insert(ans.end(), v.begin(), v.end());
        return ans;
    }

private:
    bool all_valid_chars(const string &s) {
        if(s.empty())
            return false;

        for(char c : s) {
            if(!isalnum(c) && c != '_')
                return false;
        }
        return true;
    }
};
