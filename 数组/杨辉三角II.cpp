class Solution {
public:
    //last������һ�㣬resΪ��һ����
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
            last = res;     //��������last��
        }
        return res;
    }
};