// https://walkccc.me/LeetCode/problems/0253/
// sort

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int ans = 0;
        vector<int> starts, ends;

        for(auto i : intervals) {
            starts.push_back(i[0]);
            ends.push_back(i[1]);
        }

        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());

        for(int i = 0, j = 0; i < n; i++) {
            if(starts[i] < ends[j])
                ans++;
            else
                j++;
        }
        return ans;
    }
};
