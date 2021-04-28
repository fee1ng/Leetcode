class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        //二分查找耗费最小体力的mid值能否使其到达终点
        //广度优先搜索
        vector<vector<int>> dir = { {0,1},{0,-1},{1,0},{-1,0} };

        int row = heights.size();
        int col = heights[0].size();
        int left = 0;
        int right = 10e6;
        int res = 0;

        while (left <= right)
        {
            queue<pair<int, int>> q;
            vector<vector<int>> visit(row, vector<int>(col));
            q.push({ 0,0 });
            visit[0][0] = 1;
            int mid = (left + right) / 2;
            while (!q.empty())
            {
                auto t = q.front();
                q.pop();
                int x = t.first;
                int y = t.second;
                for (int i = 0;i < 4;i++)
                {
                    int r = x + dir[i][0];
                    int c = y + dir[i][1];
                    if (r >= 0 && r < row && c >= 0 && c < col && !visit[r][c] && (abs(heights[x][y] - heights[r][c]) <= mid))
                    {
                        q.push({ r,c });
                        visit[r][c] = 1;
                    }
                }
            }
            if (visit[row - 1][col - 1])
            {
                res = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }

        }
        return res;
    }
};