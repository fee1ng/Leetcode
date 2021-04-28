class Solution {
public:
    //��ֳ��ĸ��׶�
    /*
    mΪ������nΪ����
    tmpc=c,tmpr=r
    A B C  D
    E F G  H
    I J K  L
    ��һ�׶Σ�A->D, c<n-tmpc,c++,�в��䣬��ǰ������ΧȦ
    ���һ��c++��c==n-tmpc��Ҫ��������ȥ�����򳬹���Χ��ͬʱr++,��Ϊ���ϵ������ܶ�����
    ÿ�ζ���һ���ߣ���Ҫ�ж��Ƿ��Ѿ�ȫ�����꣬�ж�����Ϊres.size()==m*n
    �ڶ��׶�: H->L, r<m-tmpr,r++���в��䣬��ǰ������ΧȦ
    ���һ��r++��r==m-tmpr,Ҫ����ȥ��ͬʱc++,��Ϊ���ϵ������ܶ�����
    ���һ������Ϊ�ߵ��������㶼�������������ж�������Ϊr>tmpr��tmpr�ǵ�һ���߶�ȡʱ������
    ��r==tmprʱ���������պûص�ԭ�㣬����r++,c++��������һ�������Ρ�
    */
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        vector<int> res;
        if (m == 0)
            return res;
        int n = matrix[0].size();
        if (n == 0)
            return res;
        int size = res.size();
        int r = 0, c = 0;
        while (size < m * n)
        {
            int tmpc = c;
            int tmpr = r;
            while (c < n - tmpc)
            {
                res.push_back(matrix[r][c]);
                c++;
            }
            c--;
            r++;
            if (res.size() == m * n)
                return res;
            while (r < m - tmpr)
            {
                res.push_back(matrix[r][c]);
                r++;
            }
            if (res.size() == m * n)
                return res;
            r--;
            c--;
            while (c >= tmpc)
            {
                res.push_back(matrix[r][c]);
                c--;
            }
            if (res.size() == m * n)
                return res;
            c++;
            r--;
            while (r > tmpr)
            {
                res.push_back(matrix[r][c]);
                r--;
            }
            r++;
            c++;
            size = res.size();
        }
        return res;
    }
};