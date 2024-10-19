class Solution {
public:
    char findKthBit(int n, int k) {
        string tmp = "0";
        for(int i = 2; i <= n; i++) {
            string s = tmp;
            s += "1";
            string t = tmp;
            for(int i = 0; i < t.size(); i++)
                t[i] = t[i] == '0' ? '1' : '0';
            reverse(t.begin(), t.end());
            s += t;
            tmp = s;
        }

        return tmp[k - 1];
    }
};
