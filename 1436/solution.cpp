// 1436. Destination City
// Count the out-degree of vertices.

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, int> out;
        for(auto e : paths) {
            string u = e[0], v = e[1];
            if(!out.count(u))
                out[u] = 0;
            if(!out.count(v))
                out[v] = 0;
            out[u]++;
        }

        string ans;
        for(auto kv : out) {
            if(kv.second == 0) {
                ans = kv.first;
                break;
            }
        }
        return ans;
    }
};
