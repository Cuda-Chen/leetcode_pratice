// math + binary search

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return false;
        if(matrix.size() == 1 && matrix[0].size() == 1) return matrix[0][0] == target;
        int m = matrix.size();
        int n = matrix[0].size();
        int l = 0, r = m * n;
        int mid;
        while(l < r) {
            int mid = l + (r - l) / 2;
            if(matrix[mid / n][mid % n] >= target)
                r = mid;
            else
                l = mid + 1;
        }
        
        // If one of index is out of bounds means target not found
        if((l / n) >= m || (l % n) >= n) return false;

        return (matrix[l / n][l % n] == target) ? true : false;
    }
};
