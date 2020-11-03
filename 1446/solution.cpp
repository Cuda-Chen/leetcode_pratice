class Solution {
public:
    int maxPower(string s) {
        vector<int> power(s.size(), 1);
        for(int i = 1; i < s.size(); i++) {
            power[i] = (s[i] == s[i - 1]) ? (power[i - 1] + 1) : 1;
        }
        return *max_element(power.begin(), power.end());
    }
};
