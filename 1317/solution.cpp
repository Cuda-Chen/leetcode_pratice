class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        for(int a = 1; a <= n - 1; a++) {
            int b = n - a;
            if(!hasZero(a) && !hasZero(b))
                return {a, b};
        }
        throw;
    }

private:
    bool hasZero(int n) {
        while(n) {
            int digit = n % 10;
            if(digit == 0)
                return true;
            n /= 10;
        }
        return false;
    }
};
