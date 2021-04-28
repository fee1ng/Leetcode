class Solution {
public:
    //�ҹ��ɣ�ԭ����[i][j]��Ԫ�ػ��ڵ�[j][c-i-1]��
    //��һ�������һ�� �ڶ����ڵ����ڶ���.......
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
    //���������������½���matrix[i][j]=matrix[n-1-i][j] i<n/2
    //���������Խ��߷�תmatrix[i][j]=matrix[j][i]   i<j
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