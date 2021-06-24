// DFS another solution
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path;
        traverse(graph, 0, path);
        return ans;
    }
    
private:
    vector<vector<int>> ans;
    void traverse(vector<vector<int>> &graph, int src, vector<int> &path) {
        path.push_back(src);
        
        if(src == graph.size() - 1) {
            ans.push_back(path);
            path.pop_back();
            return;
        }
        
        for(int v : graph[src])
            traverse(graph, v, path);
        
        path.pop_back();
    }
};
