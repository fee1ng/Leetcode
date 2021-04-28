class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int nr=grid.size();
         if(!nr)
            return 0;
        int nc=grid[0].size();
        int num=0;
        for(int i=0;i<nr;i++)
            for(int j=0;j<nc;j++)
                if(grid[i][j]=='1')
                {
                    num++;
                    dfs(grid,i,j);
                }
        return num;
    }
    void dfs(vector<vector<char>>& grid,int r,int c)
    {
        int nr=grid.size();     //行
        int nc=grid[0].size();  //列
        if(r>=nr||c>=nc)
            return;
        grid[r][c]='0';
        //开始遍历四个周围节点
        if (r - 1 >= 0 && grid[r-1][c] == '1') 
            dfs(grid, r - 1, c);
        if(r+1<nr&&grid[r+1][c]=='1')
            dfs(grid,r+1,c);
        if(c-1>=0&&grid[r][c-1]=='1')
            dfs(grid,r,c-1);
        if(c+1<nc&&grid[r][c+1]=='1')
            dfs(grid,r,c+1);
    }
};