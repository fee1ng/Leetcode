class Solution {
public:
    int res = 0;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        for (int i = 0;i < grid.size();i++)
        {
            for (int j = 0;j < grid[0].size();j++)
            {
                if (grid[i][j] == 1)
                {
                    dfs(grid, i, j);
                }
            }
        }
        return res;
    }
    int dfs(vector<vector<int>>& grid, int row, int col)
    {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] != 1)
            return 0;
        int curr = 1;
        grid[row][col] = 0;
        curr += dfs(grid, row + 1, col);
        curr += dfs(grid, row - 1, col);
        curr += dfs(grid, row, col + 1);
        curr += dfs(grid, row, col - 1);
        if (curr > res)
            res = curr;
        return curr;
    }
};