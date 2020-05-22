class Solution {
    public int[][] transpose(int[][] A) {
        int r = A.length, c = A[0].length;
        int[][] result = new int[c][r];
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                result[j][i] = A[i][j];
            }
        }
        
        return result;
    }
}
