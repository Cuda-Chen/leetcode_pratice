// greedy solution #2

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0, start = 0, mx = 0;
        for(int i = gas.size() - 1; i >= 0; i--) {
            total += gas[i] - cost[i];
            if(total > mx) {
                mx = total;
                start = i;
            }
        }
        return total < 0 ? -1 : start;
    }
};
