// heap (priority_queue)

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int stops = 0, i = 0;
        int current = startFuel;
        priority_queue<int> q;
        
        while(true) {
            if(current >= target) {
                return stops;
            }
            
            while(i < stations.size() && current >= stations[i][0]) {
                q.push(stations[i][1]);
                i++;
            }
            if(q.empty()) {
                return -1;
            }
            
            current += q.top(); q.pop();
            stops++;
        }
    }
};
