// Note that l is start from 1

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 0, r = n;
        while(l < r) {
            int mid = l + (r - l) / 2;
            if(isBadVersion(mid) )
        }
    }
};
