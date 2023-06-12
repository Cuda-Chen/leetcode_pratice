class Solution {
public:
    vector<string> summaryRanges(vector<int>& A) {
        int n = A.size();
        vector<string> ans;
        if(n == 0)
            return ans;
        if(n == 1) {
            ans.push_back(to_string(A[0]));
            return ans;
        }
        int start = A[0], end = A[0];
        for(int i = 1; i < n; i++) {
            if(A[i] != A[i - 1] + 1) {
                if(start != end) {
                    string tmp = to_string(start) + "->" + to_string(end);
                    ans.push_back(tmp);
                } else {
                    string tmp = to_string(start);
                    ans.push_back(tmp);
                }
                start = A[i];
                end = A[i];
            } else {
                end = A[i];
            }
        }
        if(start != end) {
            string tmp = to_string(start) + "->" + to_string(end);
            ans.push_back(tmp);
        } else {
            string tmp = to_string(start);
            ans.push_back(tmp);
        }
        return ans;
    }
};
