class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> m;
        for(int a : arr1) {
            int msd = (int)log10(a);
            for(int i = msd; i >= 0; i--) {
                int d = 1;
                for(int j = 0; j < i; j++)
                    d *= 10;
                int tmp = a / d;
                m.insert(tmp);
            }
        }

        int ans = 0;
        for(int a : arr2) {
            int msd = (int)log10(a);
            for(int i = msd; i >= 0; i--) {
                int d = 1;
                for(int j = 0; j < i; j++)
                    d *= 10;
                int tmp = a / d;
                if(m.count(tmp)) {
                    int cnt = 0;
                    while(tmp) {
                        cnt++;
                        tmp /= 10;
                    }
                    ans = max(ans, cnt);
                }
            }
        }
        return ans;
    }
};
