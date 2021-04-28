// 任何不在边界上，或不与边界上的 'O' 相连的 'O' 最终都会被填充为 'X'
//找到边界上的及与其相连的O并做标记
//然后根据标记赋值表格

void solve(vector<vector<char>>& board) {
    int n = board.size();
    if (n == 0)
        return;
    int c = board[0].size();
    for (int i = 0;i < n;i++)
    {
        dfs(board, i, 0);
        dfs(board, i, c - 1);
    }
    for (int i = 1;i < c - 1;i++)
    {
        dfs(board, 0, i);
        dfs(board, n - 1, i);
    }
    for (int i = 0;i < n;i++)
        for (int j = 0;j < c;j++)
        {
            if (board[i][j] == 'A')
                board[i][j] = 'O';
            else if (board[i][j] == 'O')
                board[i][j] = 'X';
        }
}
void dfs(vector<vector<char>>& board, int x, int y)
{
    if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size())
        return;
    if (board[x][y] != 'O')
        return;
    board[x][y] = 'A';
    dfs(board, x - 1, y);
    dfs(board, x + 1, y);
    dfs(board, x, y - 1);
    dfs(board, x, y + 1);
}