class Solution {
public:
    int rows, cols;
    int dir[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
    //dfs�����ڵ������⣬��ʹ�ü��仯dfs�����ظ�����ĳ���ڵ�
    //memo[i][j]����ǰλ�õ��������·�����ȣ���Ҫע�����ͬһ����Ԫ���Ӧ�������·���ĳ����ǹ̶������
    //������memo[i][j]�Ѿ���Ϊ0��������Դ˵�Ԫ�����dfs��ֱ�ӷ��ظõ�Ԫ���Ӧ�ĵ���·������
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        rows = matrix.size();
        cols = matrix[0].size();
        auto memo = vector<vector<int>>(rows, vector<int>(cols, 0));
        int res = 0;
        //��ÿһ���ڵ㿪ʼ����һ�������·������ʱ����
        for (int i = 0;i < rows;++i)
            for (int j = 0;j < cols;++j)
                res = max(res, dfs(matrix, i, j, memo));
        return res;
    }
    int dfs(vector<vector<int>>& matrix, int row, int col, vector<vector<int>>& memo)
    {
        if (memo[row][col] != 0)
            return memo[row][col];
        ++memo[row][col];   //�����Լ����ٵ�������Ϊ1
        for (int i = 0;i < 4;++i)
        {
            int newRow = row + dir[i][0];
            int newCol = col + dir[i][1];
            if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol<cols && matrix[newRow][newCol]>matrix[row][col])
            {   
                //�����ĸ����򣬵�ǰ��Ԫ��������·������Ҫô�Ǳ���Ҫô��dfs��Ľ��
                //Ҳ���һ������Ľ�����ĸ������������ģ�Ҳ���ǵڶ���
                memo[row][col] = max(memo[row][col], dfs(matrix, newRow, newCol, memo) + 1);    
            }
        }
        return memo[row][col];
    }
};