// segment tree

class NumArray {
public:
    NumArray(vector<int>& nums) : size(nums.size()), st(nums.size() * 4) {
        init(1, 0, size - 1, nums);
    }
    
    int sumRange(int left, int right) {
        return query(1, 0, size - 1, left, right);
    }
    
private:
    int size;
    vector<int> st;
    
    void init(int id, int l, int r, vector<int> &nums) {
        if(l == r) {
            st[id] = nums[l];
            return;
        }
        int mid = l + (r - l) / 2;
        init(id * 2, l, mid, nums);
        init(id * 2 + 1, mid + 1, r, nums);
        st[id] = st[id * 2] + st[id * 2 + 1];
    }
    
    int query(int id, int l, int r, int L, int R) {
        if(r < L || R < l) return 0;
        if(L <= l && r <= R) return st[id];
        int mid = l + (r - l) / 2;
        return query(id * 2, l, mid, L, R) + query(id * 2 + 1, mid + 1, r, L, R);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
