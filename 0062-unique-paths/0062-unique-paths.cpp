class Solution {
public:
    int solve(int i,int j,int m,int n,vector<vector<int>>& dp){
        if(i==m-1 && j==n-1){
            return 1;
        }
        if(i>=m || j>=n ){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int d=solve(i+1,j,m,n,dp);
        int r=solve(i,j+1,m,n,dp);
        dp[i][j]=d+r;
        return dp[i][j];
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        int ans=solve(0,0,m,n,dp);
        return ans;
    }
};