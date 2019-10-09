def DFS(grid, i, j)
    if i < 0 || j < 0 || i > grid.length - 1 || j > grid[0].length - 1 || grid[i][j] == 0
        return 0
    end
    
    grid[i][j] = 0
    
    return 1 + DFS(grid, i - 1, j) + DFS(grid, i + 1, j) + DFS(grid, i, j - 1) + DFS(grid, i, j + 1)
end

# @param {Integer[][]} grid
# @return {Integer}
def max_area_of_island(grid)
    maxArea = 0
    
    for i in 0..grid.length - 1
        for j in 0..grid[0].length - 1
            maxArea = [maxArea, DFS(grid, i, j)].max
        end
    end
    
    return maxArea
end
