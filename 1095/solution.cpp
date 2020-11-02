// https://leetcode-cn.com/problems/find-in-mountain-array/solution/shan-mai-shu-zu-zhong-cha-zhao-mu-biao-zhi-by-leet/
// binary search

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int l = 0, r = mountainArr.length() - 1;
        while(l < r) {
            int mid = l + (r - l) / 2;
            if(mountainArr.get(mid) < mountainArr.get(mid + 1)) 
                l = mid + 1;
            else
                r = mid;
        }
        
        int peak = l;
        int index = binarySearch(mountainArr, target, 0, peak + 1, [](int x) -> int { return x; });
        return (index != -1) ? index : binarySearch(mountainArr, target, peak + 1, mountainArr.length(), [](int x) -> int { return -x; });
    }
    
    int binarySearch(MountainArray &mountainArr, int target, int l, int r, int key(int)) {
        target = key(target);
        while(l < r) {
            int mid = l + (r - l) / 2;
            int current = key(mountainArr.get(mid));
            if(current == target)
                return mid;
            else if(current < target)
                l = mid + 1;
            else
                r = mid;
        }
        return -1;
    }
};
