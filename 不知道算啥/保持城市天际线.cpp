class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        //求每一列和每一行的最大值maxRow和maxCol，确定每一点的最大值为currMax=min(maxRow,maxCol)
        //增量即为currMax-grid[i][j]
        int row = grid.size();
        int col = grid[0].size();
        vector<int> maxRow(row);
        vector<int> maxCol(col);
        int m = 0;
        for (int r = 0;r < row;r++)
        {
            for (int c = 0;c < col;c++)
            {
                if (grid[r][c] > m)
                    m = grid[r][c];
            }
            maxRow[r] = m;
            m = 0;
        }
        for (int c = 0;c < col;c++)
        {
            for (int r = 0;r < row;r++)
            {
                if (grid[r][c] > m)
                    m = grid[r][c];
            }
            maxCol[c] = m;
            m = 0;
        }
        int res = 0;
        for (int i = 0;i < row;i++)
            for (int j = 0;j < col;j++)
            {
                res += min(maxRow[i], maxCol[j]) - grid[i][j];
            }
        return res;
    }
};