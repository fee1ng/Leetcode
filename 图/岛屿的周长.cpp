  //Ҫ���ܳ���������ʲôʱ���±߿��Ա���Ϊ�ܳ�
  //1.������ͼ�ı�Ե
  //2.�����뺣��Ľ���

int islandPerimeter(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[0].size();j++)
                if(grid[i][j]==1)
                    return dfs(grid,i,j);
        return 0;
    }
    int dfs(vector<vector<int>>& grid,int r,int c)
    {
        int nr=grid.size();   //    hang
        int nc=grid[0].size();//    lie
        if(!isone(grid,r,c))//�õ㲻�ڵ�ͼ�ڣ�����������ͼ���ˣ��б�
            return 1;
        if(grid[r][c]==0)   //�뺣��Ľ���
            return 1;
        if(grid[r][c]!=1)   //��������½��
            return 0;
        grid[r][c]=2;       //������½�صı�־
        return dfs(grid,r-1,c)+dfs(grid,r+1,c)+dfs(grid,r,c-1)+dfs(grid,r,c+1);
    }
    bool isone(vector<vector<int>>& grid,int r,int c)
    {
        if(0<=r&&r<grid.size()&&0<=c&&c<grid[0].size())
            return true;
        else
            return false;
    }



    //���ڵ����ǶԳƵģ������ܳ���һ�뼴��
    int islandPerimeter(vector<vector<int>>& grid) {
        int res = 0;
        for (int r = 0;r < grid.size();r++)
            for (int c = 0;c < grid[0].size();c++)
                if (grid[r][c] == 1)
                {
                    if (r == 0 || grid[r - 1][c] == 0)
                        res++;
                    if (c == 0 || grid[r][c - 1] == 0)
                        res++;
                }
        return res * 2;
    }