//»ØËÝ
class Solution {
public:
    int movingCount(int m, int n, int k) {
        vector<vector<bool>> visit(m, vector<bool>(n));
        int count = dfs(m, n, k, 0, 0, visit);
        return count;
    }
    int dfs(int m, int n, int k, int row, int col, vector<vector<bool>>& visit)
    {
        int count = 0;
        if (check(m, n, k, row, col, visit))
        {
            visit[row][col] = true;
            count = 1 +
                dfs(m, n, k, row + 1, col, visit)
                + dfs(m, n, k, row, col + 1, visit)
                + dfs(m, n, k, row - 1, col, visit)
                + dfs(m, n, k, row, col - 1, visit);
        }
        return count;
    }
    bool check(int m, int n, int k, int row, int col, vector<vector<bool>>& visit)
    {
        if (row >= 0 && row < m && col >= 0 && col < n && !visit[row][col] && getsum(row) + getsum(col) <= k)
            return true;
        return false;
    }
    int getsum(int m)
    {
        int sum = 0;
        while (m > 0)
        {
            sum += m % 10;
            m = m / 10;
        }
        return sum;
    }
};