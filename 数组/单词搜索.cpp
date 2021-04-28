class Solution {
public:
    //二维数组上图的遍历
    //状态设置避免重复遍历(参考图的遍历)，但回溯后要取消状态设置(即设置该位置未被遍历过)，以让前一个状态遍历(它可以被再次使用)
    //k表示单词word的第k位，i,j为图上的每个顶点，查询从每个顶点出发的n条路径是否有单词word
    //退出条件:若当前board[i][j]!word[k]，则不匹配，或者k已经遍历完word且前面都匹配，则返回true
    bool help(vector<vector<char>>& board, vector<vector<int>>& visit, int i, int j, int k, string& word, int m, int n)
    {
        if (board[i][j] != word[k])
            return false;
        else if (k == word.size() - 1)
            return true;
        vector<pair<int, int>> dir = { {0,1},{0,-1},{1,0},{-1,0} };
        visit[i][j] = true;
        bool res = false;
        for (auto& d : dir)
        {
            int currI = i + d.first;
            int currJ = j + d.second;
            if (currI >= 0 && currI < m && currJ >= 0 && currJ < n)
            {
                if (!visit[currI][currJ])
                {
                    bool flag = help(board, visit, currI, currJ, k + 1, word, m, n);
                    if (flag)
                    {
                        res = true;
                        break;
                    }
                }
            }
        }
        visit[i][j] = false;
        return res;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> visit(m, vector<int>(n));
        for (int i = 0;i < m;i++)
        {
            for (int j = 0;j < n;j++)
            {
                bool flag = help(board, visit, i, j, 0, word, m, n);
                if (flag)
                    return true;
            }
        }
        return false;
    }
};