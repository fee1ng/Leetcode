  //要求周长，即考虑什么时候下边可以被算为周长
  //1.岛屿在图的边缘
  //2.岛屿与海面的交界

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
        if(!isone(grid,r,c))//该点不在地图内，即遍历到地图外了，有边
            return 1;
        if(grid[r][c]==0)   //与海面的交界
            return 1;
        if(grid[r][c]!=1)   //遍历过的陆地
            return 0;
        grid[r][c]=2;       //遍历过陆地的标志
        return dfs(grid,r-1,c)+dfs(grid,r+1,c)+dfs(grid,r,c-1)+dfs(grid,r,c+1);
    }
    bool isone(vector<vector<int>>& grid,int r,int c)
    {
        if(0<=r&&r<grid.size()&&0<=c&&c<grid[0].size())
            return true;
        else
            return false;
    }



    //由于岛屿是对称的，所以周长算一半即可
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