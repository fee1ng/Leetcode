class Solution {
public:
    //��i>=2ʱ�����������㣬��v[j]=res[i-1][j]+res[i-1][j-1]������һ��������������һ�����
    //���Ƶ�ǰ��Ľ�������Ϊj>=i�������һ��������Ҫ�ı䣬j�ĳ�ʼֵΪ1
    //v[0]=v[i]=1����n����n����
    vector<vector<int>> generate(int numRows) {
        if (numRows == 0)
            return{};
        vector<vector<int>> res;
        for (int i = 0;i < numRows;i++)
        {
            vector<int> v(i + 1);
            v[0] = 1;
            v[i] = 1;
            int j = 1;
            while (j < i)
            {
                v[j] = res[i - 1][j] + res[i - 1][j - 1];
                j++;
            }
            res.push_back(v);
        }
        return res;
    }
};