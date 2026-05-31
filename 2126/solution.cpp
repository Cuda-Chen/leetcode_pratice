class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& A) {
        ranges::sort(A);
        long tmp = mass;

        for(int a : A) {
            if(tmp < a)
                return false;
            tmp += a;
        }
        return true;
    }
};
