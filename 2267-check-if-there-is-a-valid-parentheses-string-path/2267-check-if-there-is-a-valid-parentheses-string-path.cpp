class Solution {
public:
    bool validpath(int i,int j,int balance,vector<vector<char>>& grid,int n,int m,vector<vector<vector<int>>>&dp){
        if(i>=n || j>=m){
            return false;
        }
        if(grid[i][j]=='('){
            balance++;
        }
        else{
            balance--;
        }
        if(balance<0){
            return false;
        }
        if(i==n-1 && j==m-1){
            return balance==0;
        }
        if(dp[i][j][balance]!=-1){
            return dp[i][j][balance];
        }
        dp[i][j][balance]=validpath(i+1,j,balance,grid,n,m,dp) || validpath(i,j+1,balance,grid,n,m,dp);
        return dp[i][j][balance];
        
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(n+m,-1)));
        if(validpath(0,0,0,grid,n,m,dp)){
            return true;
        }
        return false;
    }
};