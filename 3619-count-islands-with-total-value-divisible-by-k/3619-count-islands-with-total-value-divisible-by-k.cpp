class Solution {
public:
    int m,n;
    void dfs(vector<vector<int>>&grid,int i,int j,long long & s){
        if(i>=m || i<0 || j>=n || j<0 || grid[i][j]==0){
            return;
        }
        s+=grid[i][j];
        grid[i][j]=0;
        dfs(grid,i,j-1,s);
        dfs(grid,i,j+1,s);
        dfs(grid,i-1,j,s);
        dfs(grid,i+1,j,s);
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        m=grid.size();
        n=grid[0].size();
        int c=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=0){
                    long long s=0;
                    dfs(grid,i,j,s);
                    if(s%k==0){
                        c++;
                    }
                }
            }
        }
        return c;
        
    }
};