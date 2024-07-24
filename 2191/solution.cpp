struct node {
    int map;
    int idx;
};

class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = nums.size();
        vector<struct node> v;
        for(int i = 0; i < n; i++) {
            int tmp = 0;
            int val = nums[i];
            int place = 1;
            if(val == 0) {
                tmp = mapping[val];
                goto store;          
            }
            
            while(val) {
                tmp = place * mapping[val % 10] + tmp;
                place *= 10;
                val /= 10;
            }

store:
            struct node p = {
                tmp,
                i,
            };
            v.push_back(p);
        }

        ranges::sort(v, [](const struct node &a, const struct node &b) {
            if(a.map == b.map)
                return a.idx < b.idx;
            return a.map < b.map;
        });

        vector<int> ans;
        for(int i = 0; i < n; i++) {
            ans.push_back(nums[v[i].idx]);
        }
        return ans;
    }
};
