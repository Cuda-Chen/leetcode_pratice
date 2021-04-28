// segment tree

class NumArray {
public:
    NumArray(vector<int>& nums) : size(nums.size()), st(nums.size() * 4) {
        init(1, 0, size - 1, nums);
    }
    
    void update(int index, int val) {
        update(1, 0, size - 1, index, val);
    }
    
    int sumRange(int left, int right) {
        return query(1, 0, size - 1, left, right);
    }
    
private:
    int size;
    vector<int> st;
    
    void init(int id, int l, int r, const vector<int> &arr) {
        if(l == r) {
            st[id] = arr[l];
            return;
        }
        int mid = l + (r - l) / 2;
        init(id * 2, l, mid, arr);
        init(id * 2 + 1, mid + 1, r, arr);
        st[id] = st[id * 2] + st[id * 2 + 1];
    }
    
    void update(int id, int l, int r, int pos, int val) {
        if(l == r) {
            st[id] = val;
            return;
        }
        int mid = l + (r - l) / 2;
        if(pos <= mid) update(id * 2, l, mid, pos, val);
        else update(id * 2 + 1, mid + 1, r, pos, val);
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
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
