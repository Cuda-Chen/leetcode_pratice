class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int a = -1, b = -1;
        int ans = 0;
        for(string bb : bank) {
            int cnt = 0;
            for(char c : bb) {
                if(c == '1')
                    cnt++;
            }

            if(cnt == 0)
                continue;
            if(a == -1) {
                a = cnt;
                continue;
            }
            b = cnt;
            ans += (a * b);
            a = b;
        }
        return ans;
    }
};
