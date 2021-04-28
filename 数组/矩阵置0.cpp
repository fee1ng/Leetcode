class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //O(m+n)

        int r = matrix.size();
        if (r == 0)
            return;
        int c = matrix[0].size();
        if (c == 0)
            return;
        vector<int> v1;
        vector<int> v2;
        int index = 0;
        for (int i = 0;i < r;i++)
            for (int j = 0;j < c;j++)
            {
                if (matrix[i][j] == 0)
                {
                    v1.push_back(i);    //ĳ�д���0������ж�Ϊ0
                    v2.push_back(j);    //ĳ�д���0������ж�Ϊ0
                }
            }
        for (int i = 0;i < r;i++)
        {
            auto it = find(v1.begin(), v1.end(), i);    //�Ҹ����Ƿ���0
            if (it != v1.end())
            {
                for (int k = 0;k < c;k++)
                    matrix[*it][k] = 0;
            }
        }
        for (int j = 0;j < c;j++)
        {
            auto it2 = find(v2.begin(), v2.end(), j);       //�Ҹ����Ƿ���0
            if (it2 != v2.end())
            {
                for (int k = 0;k < r;k++)
                    matrix[k][*it2] = 0;
            }
        }
    }
};