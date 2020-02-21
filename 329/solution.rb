# DFS + memorization

# @param {Integer[][]} matrix
# @return {Integer}
def longest_increasing_path(matrix)
    result = 0
    return result if matrix.empty?
    n, m = matrix.size, matrix[0].size
    dp = Array.new(n) {Array.new(m, -1)}
    
    n.times do |i|
        m.times do |j|
            result = [result, DFS(matrix, i, j, n, m, dp)].max
        end
    end
    
    result
end

def DFS(matrix, i, j, n, m, dp)
    return dp[i][j] if dp[i][j] != -1
    
    dp[i][j] = 1
    dirs = [0, 1, 0, -1, 0]
    4.times do |k|
        x, y = i + dirs[k], j + dirs[k + 1]
        if x < 0 || y < 0 || x >= n || y >= m || matrix[x][y] <= matrix[i][j]
            next
        end
        dp[i][j] = [dp[i][j], 1 + DFS(matrix, x, y, n, m, dp)].max
    end
    
    dp[i][j]
end
