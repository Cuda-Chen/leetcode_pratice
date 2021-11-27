// https://www.cnblogs.com/grandyang/p/4843654.html
// two pointers
// refer to "Linked List Cycle II"

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;
        while(true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow == fast) break;
        }
        slow = 0;
        while(true) {
            slow = nums[slow];
            fast = nums[fast];
            if(slow == fast) break;
        }
        return slow;
    }
};
