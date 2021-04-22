// naive

class NumArray {
public:
    NumArray(vector<int>& nums) {
        arr = vector<int>(nums);
    }
    
    int sumRange(int left, int right) {
        int result = 0;
        for(int i = left; i <= right; i++)
            result += arr[i];
        return result;
    }
    
private:
    vector<int> arr;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
