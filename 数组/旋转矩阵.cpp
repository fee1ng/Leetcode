class Solution {
public:
    //找规律，原本第[i][j]个元素会在第[j][c-i-1]上
    //第一行在最后一列 第二行在倒数第二列.......
    void rotate(vector<vector<int>>& matrix) {
        int r = matrix.size();
        if (r == 0)
            return;
        int c = matrix[0].size();
        if (c == 0)
            return;
        auto v = matrix;
        for (int i = 0;i < r;i++)
            for (int j = 0;j < c;j++)
            {
                v[j][c - 1 - i] = matrix[i][j];
            }
        matrix = v;
    }
};


class Solution {
public:
    //先沿着行中线上下交换matrix[i][j]=matrix[n-1-i][j] i<n/2
    //再沿着主对角线反转matrix[i][j]=matrix[j][i]   i<j
    void rotate(vector<vector<int>>& matrix) {
        int r = matrix.size();
        if (r == 0)
            return;
        int c = matrix[0].size();
        if (c == 0)
            return;
        for (int i = 0;i < r / 2;i++)
            for (int j = 0;j < c;j++)
            {
                swap(matrix[i][j], matrix[r - i - 1][j]);
            }
        for (int i = 0;i < r;i++)
            for (int j = 0;j < i;j++)
                swap(matrix[i][j], matrix[j][i]);

    }
};