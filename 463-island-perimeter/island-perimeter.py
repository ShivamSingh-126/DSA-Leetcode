class Solution:
    def islandPerimeter(self, grid: list[list[int]]) -> int:

        
        m=len(grid)
        n=len(grid[0])
        peri=0

        # def dfs(i,j):
        #     nonlocal peri

        #     if i<0 or i>=m or j<0 or j>=n or grid[i][j] == 0:
        #         peri += 1
        #         return

        #     if grid[i][j] == -1:
        #         return

        #     grid[i][j] = -1

        #     dfs(i+1,j)
        #     dfs(i-1,j)
        #     dfs(i,j+1)
        #     dfs(i,j-1)


        # for i in range(m):
        #     for j in range(n):
        #         if grid[i][j] == 1:
        #             dfs(i,j)
        #             return peri
        
        # return 0

        for i in range(m):
            for j in range(n):

                if grid[i][j]==0:
                    continue

                if j+1 >= n or grid[i][j+1] == 0:
                    peri+=1
                if j-1 < 0 or grid[i][j-1] == 0:
                    peri+=1
                if i+1 >= m or grid[i+1][j] == 0:
                    peri+=1
                if i-1 < 0 or grid[i-1][j] == 0:
                    peri+=1

        return peri
        