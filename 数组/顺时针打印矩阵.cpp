class Solution {
public:
    //拆分成四个阶段
    /*
    m为行数，n为列数
    tmpc=c,tmpr=r
    A B C  D
    E F G  H
    I J K  L
    第一阶段：A->D, c<n-tmpc,c++,行不变，列前进到包围圈
    最后一次c++令c==n-tmpc，要把它减回去，否则超过范围，同时r++,因为边上的数不能读两次
    每次读完一条边，需要判断是否已经全部读完，判断条件为res.size()==m*n
    第二阶段: H->L, r<m-tmpr,r++，列不变，行前进到包围圈
    最后一次r++令r==m-tmpr,要减回去，同时c++,因为边上的数不能读两次
    最后一条边因为边的两个顶点都被读过，所以判断条件变为r>tmpr，tmpr是第一条边读取时的行数
    到r==tmpr时，跳出，刚好回到原点，进行r++,c++迭代到下一个长方形。
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