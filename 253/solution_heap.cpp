// https://walkccc.me/LeetCode/problems/0253/
// heap

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        priority_queue<int, vector<int>, greater<int>> q;
        for(auto i : intervals) {
            if(!q.empty() && i[0] >= q.top())
                q.pop();
            q.push(i[1]);
        }

        return q.size();
    }
};
