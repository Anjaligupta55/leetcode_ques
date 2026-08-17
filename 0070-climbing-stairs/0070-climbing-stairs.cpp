class Solution {
public:
    int sol(int n,vector<int>&dp){
        if(dp[n]!=-1){
            return dp[n];
        }
        if(n<=2){
            return dp[n]=n;
        }
        dp[n]=sol(n-1,dp)+sol(n-2,dp);
        return dp[n];
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        int ans=sol(n,dp);
        return ans;
    }

};