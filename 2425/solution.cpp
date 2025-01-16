// If the size of nums1 is m and the size of nums2 is n, then each number in
// nums1 is repeated n times and each number in nums2 is repeated m times.

class Solution {
public:
    int xorAllNums(vector<int>& A, vector<int>& B) {
        int ans = 0;
        if(A.size() % 2 == 1) {
            for(int b : B)
                ans ^= b;
        }
        if(B.size() % 2 == 1) {
            for(int a : A)
                ans ^= a;
        }
        return ans;
    }
};
