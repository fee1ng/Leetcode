class Solution {
public:
    //当i>=2时，即到第三层，有v[j]=res[i-1][j]+res[i-1][j-1]，即上一层的两个数组成下一层的数
    //完善当前层的结束条件为j>=i，即最后一个数不需要改变，j的初始值为1
    //v[0]=v[i]=1，第n层有n个数
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