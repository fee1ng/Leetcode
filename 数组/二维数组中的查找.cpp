class Solution {
public:
    //缩小范围在其中遍历
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if (n == 0)
            return false;
        if (matrix[0].size() == 0)
            return false;
        int m = matrix[0].size();
        int r = n - 1;    //行
        int c = m - 1;    //列
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
    //从第一行右上角开始比较
    //如果matrix[r][c]==target，返回true
    //如果matrix[r][c]>target，则目标范围在左下方，则剔除所在的列，即c--
    //若matrix[r][c]<target，，则目标在下方(因为列数的递减的)，剔除所在的行，即r++
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