class Solution {
public:
    //��С��Χ�����б���
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if (n == 0)
            return false;
        if (matrix[0].size() == 0)
            return false;
        int m = matrix[0].size();
        int r = n - 1;    //��
        int c = m - 1;    //��
        for (int j = 0;j < m;j++)
        {
            if (matrix[0][j] >= target)
            {
                c = j;
                break;
            }
        }
        for (int i = 0;i < n;i++)
        {
            if (matrix[i][0] >= target)
            {
                r = i;
                break;
            }
        }
        for (int i = 0;i <= r;i++)
            for (int j = 0;j <= c;j++)
            {
                if (matrix[i][j] == target)
                    return true;
            }
        return false;

    }
};


class Solution {
public:
    //�ӵ�һ�����Ͻǿ�ʼ�Ƚ�
    //���matrix[r][c]==target������true
    //���matrix[r][c]>target����Ŀ�귶Χ�����·������޳����ڵ��У���c--
    //��matrix[r][c]<target������Ŀ�����·�(��Ϊ�����ĵݼ���)���޳����ڵ��У���r++
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if (n == 0)
            return false;
        int m = matrix[0].size();
        if (m == 0)
            return false;
        int r = 0;    //hang
        int c = m - 1;  //lie
        while (r < n && c >= 0)
        {
            if (matrix[r][c] == target)
                return true;
            else if (matrix[r][c] > target)
                c--;
            else
                r++;
        }
        return false;
    }
};