// sort then check

class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if(intervals.size() <= 1)
            return true;
        sort(intervals.begin(), intervals.end());
        int end = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i][0] < end)
                return false;
            end = intervals[i][1];
        }
        return true;
    }
};
