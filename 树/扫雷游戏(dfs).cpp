class Solution {
public:
    vector<vector<int>> dir = { {0,1},{0,-1},{1,0},{-1,0},{-1,-1},{1,1},{-1,1},{1,-1} };
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int row = click[0];
        int col = click[1];
        if (board[row][col] != 'M')
            dfs(board, row, col);
        else
            board[row][col] = 'X';
        return board;
    }
    void dfs(vector<vector<char>>& board, int row, int col)
    {

        int res = 0;
        for (int i = 0;i < 8;i++)
        {
            int r = row + dir[i][0];
            int c = col + dir[i][1];
            if (r >= 0 && r < board.size() && c >= 0 && c < board[0].size())
            {
                if (board[r][c] == 'M')
                {
                    res++;
                }
            }
        }
        if (res > 0)
            board[row][col] = res + '0';
        else
        {
            board[row][col] = 'B';
            for (int i = 0;i < 8;i++)
            {
                int r = row + dir[i][0];
                int c = col + dir[i][1];
                if (r >= 0 && r < board.size() && c >= 0 && c < board[0].size())
                {
                    if (board[r][c] != 'E')
                        continue;
                    dfs(board, r, c);
                }
            }
        }
    }
};