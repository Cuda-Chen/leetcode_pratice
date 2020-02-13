// DFS

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        vector<int> path(1, 0);
        DFS(graph, 0, graph.size() - 1, path, result);
        return result;
    }
    
private:
    void DFS(vector<vector<int>>& graph, int cur, int dst, vector<int>& path, vector<vector<int>>& result) {
        if(cur == dst) {
            result.push_back(path);
            return;
        }
        
        for(int next: graph[cur]) {
            path.push_back(next);
            DFS(graph, next, dst, path, result);
            path.pop_back();
        }
    }
};
