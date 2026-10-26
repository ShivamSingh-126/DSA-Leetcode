class Solution:
    def closedIsland(self, grid: list[list[int]]) -> int:
        m=len(grid)
        n=len(grid[0])
        count=0

        def dfs(grid,r,c):
            if r >= m or r < 0 or c >= n or c < 0:  #out of bound 
                return False

            if grid[r][c] == 1:     #check visited
                return True

            grid[r][c] = 1      #mark visited

            left_check = dfs(grid,r,c-1)
            right_check = dfs(grid,r,c+1)
            top_check = dfs(grid , r-1,c)
            bottom_check = dfs(grid,r+1,c)

            return left_check and right_check and top_check and bottom_check

        for i in range(m):
            for j in range(n):
                if grid[i][j] == 0:
                    if dfs(grid,i,j) == True:
                        count +=1

        return count