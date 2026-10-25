class Solution {
public:
    void dfs(vector<vector<int>>&grid,int i,int j,int n,int m,int & c){
        if(i>=n || i<0 || j>=m || j<0 || grid[i][j]==0){
            return ;
        }
        grid[i][j]=0;
        c++;
        dfs(grid,i,j-1,n,m,c);
        dfs(grid,i,j+1,n,m,c);
        dfs(grid,i-1,j,n,m,c);
        dfs(grid,i+1,j,n,m,c);
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    int c=0;
                    dfs(grid,i,j,n,m,c);
                    ans=max(ans,c);
                }
            }
        }
        return ans;
    }
};