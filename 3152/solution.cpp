// use binary search to the start in interval then check whether end is in the same interval of start or not

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& A, vector<vector<int>>& queries) {
        int n = A.size();

        vector<bool> ans(queries.size(), false);
        int idx = 0; // start index of special
        int cur = A[0];
        vector<int> start, end; // start and end of specials
        int i;
        for(i = 1; i < n; i++) {
            if(
                (cur % 2 == 0 && A[i] % 2 == 1) ||
                (cur % 2 == 1 && A[i] % 2 == 0)
            ) {
                // switch
                cur = A[i];
                continue;
            }

            start.push_back(idx);
            end.push_back(i - 1);
            idx = i;
            cur = A[i];
        }
        // deal with leftover
        if(i - idx > 1) {
            start.push_back(idx);
            end.push_back(i - 1);
        }

        for(i = 0; i < queries.size(); i++) {
            int s = queries[i][0];
            int e = queries[i][1];
            int ii = b_search(start, s);

            if(
                (s == e) ||
                (ii < start.size() && e <= end[ii])
            )
                ans[i] = true;
        }

        return ans;
    }

private:
    // Return the index of less than or equal to target.
    int b_search(vector<int> &A, int target) {
        int l = 0;
        int r = A.size();
        while(l < r) {
            int m = l + (r - l) / 2;
            if(A[m] <= target)
                l = m + 1;
            else
                r = m;
        }
        return l - 1;
    }
};
