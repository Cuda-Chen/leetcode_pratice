class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;
        for(string d : details) {
            int age = 0;
            age = (d[11] - '0') * 10 + (d[12] - '0');
            if(age > 60)
                ans++;
        }
        return ans;
    }
};
