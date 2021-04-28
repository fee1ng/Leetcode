class Solution {
public:
    int rows, cols;
    int dir[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
    //dfs类似于岛屿问题，但使用记忆化dfs避免重复遍历某个节点
    //memo[i][j]代表当前位置的最长递增的路径长度，需要注意的是同一个单元格对应的最长递增路径的长度是固定不变的
    //所以若memo[i][j]已经不为0，则无需对此单元格进行dfs，直接返回该单元格对应的递增路径长度
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        rows = matrix.size();
        cols = matrix[0].size();
        auto memo = vector<vector<int>>(rows, vector<int>(cols, 0));
        int res = 0;
        //从每一个节点开始，找一条最长递增路径，及时更新
        for (int i = 0;i < rows;++i)
            for (int j = 0;j < cols;++j)
                res = max(res, dfs(matrix, i, j, memo));
        return res;
    }
    int dfs(vector<vector<int>>& matrix, int row, int col, vector<vector<int>>& memo)
    {
        if (memo[row][col] != 0)
            return memo[row][col];
        ++memo[row][col];   //算上自己至少递增长度为1
        for (int i = 0;i < 4;++i)
        {
            int newRow = row + dir[i][0];
            int newCol = col + dir[i][1];
            if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol<cols && matrix[newRow][newCol]>matrix[row][col])
            {   
                //考虑四个方向，当前单元格的最长递增路径长度要么是本身，要么是dfs后的结果
                //也许第一个方向的结果在四个方向中是最大的，也许是第二个
                memo[row][col] = max(memo[row][col], dfs(matrix, newRow, newCol, memo) + 1);    
            }
        }
        return memo[row][col];
    }
};