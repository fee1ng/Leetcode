class Solution {
public:
    //��ά������ͼ�ı���
    //״̬���ñ����ظ�����(�ο�ͼ�ı���)�������ݺ�Ҫȡ��״̬����(�����ø�λ��δ��������)������ǰһ��״̬����(�����Ա��ٴ�ʹ��)
    //k��ʾ����word�ĵ�kλ��i,jΪͼ�ϵ�ÿ�����㣬��ѯ��ÿ�����������n��·���Ƿ��е���word
    //�˳�����:����ǰboard[i][j]!word[k]����ƥ�䣬����k�Ѿ�������word��ǰ�涼ƥ�䣬�򷵻�true
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