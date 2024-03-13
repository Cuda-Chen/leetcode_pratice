// prefix sum

class Solution {
public:
    int pivotInteger(int n) {
        if(n == 1)
            return 1;

        int s1 = 1, s2 = 0;
        for(int i = 1; i <= n; i++)
            s2 += i;
        s2 -= 1;

        for(int i = 2; i <= n; i++) {
            s1 += i;
            if(s1 == s2)
                return i;
            s2 -= i;
        }
        return -1;
    }
};
