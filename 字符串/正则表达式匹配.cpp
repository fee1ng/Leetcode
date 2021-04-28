class Solution {
public:
    //������ f[i][j]��ʾ ss ��ǰi���ַ���p�е�ǰj���ַ��Ƿ��ܹ�ƥ�䡣
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();

        auto matches = [&](int i, int j) {
            if (i == 0) {
                return false;
            }
            if (p[j - 1] == '.') {
                return true;
            }
            return s[i - 1] == p[j - 1];
        };

        vector<vector<int>> f(m + 1, vector<int>(n + 1));
        f[0][0] = true;
        for (int i = 0; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                //����a*
                if (p[j - 1] == '*')
                {
                    //��ƥ��*��
                    f[i][j] |= f[i][j - 2];
                    //ƥ��*��
                    if (matches(i, j - 1))
                    {
                        f[i][j] |= f[i - 1][j];
                    }
                }
                else
                {
                    //ֻ�Ƚ�Сд��ĸ�Ƿ��Ӧ
                    if (matches(i, j))
                    {
                        f[i][j] |= f[i - 1][j - 1];
                    }
                }
            }
        }
        return f[m][n];
    }
};