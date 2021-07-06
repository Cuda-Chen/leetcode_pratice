// naive
// Create an array to hold number of occurrence.

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        vector<int> map(1e5 + 1, 0);
        for(int elem : arr)
            map[elem]++;
        int n = arr.size();
        int target = n / 2;

        sort(map.begin(), map.end(), std::greater<>());

        int ans = 0;
        while(n > target) {
            n -= map[ans];
            ans++;
        }

        return ans;
    }
};
