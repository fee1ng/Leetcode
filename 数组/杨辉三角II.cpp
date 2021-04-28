class Solution {
public:
    //last保存上一层，res为这一层结果
    vector<int> getRow(int rowIndex) {
        vector<int> last(rowIndex + 1);
        vector<int> res(rowIndex + 1);
        for (int i = 0;i <= rowIndex;i++)
        {
            res[0] = 1;
            res[i] = 1;
            int j = 1;
            while (j < i)
            {
                res[j] = last[j - 1] + last[j];
                j++;
            }
            last = res;     //迭代更新last层
        }
        return res;
    }
};