class Solution {
public:
    int solve(int i,int t,vector<vector<int>>&dp,vector<int>&coins){
        if(i==0){
            if(t%coins[i]==0){
                return t/coins[i];
            }
            return 1e9;
        }
        if(dp[i][t]!=-1){
            return dp[i][t];
        }
        int nottake=0+solve(i-1,t,dp,coins);
        int take=1e9;
        if(coins[i]<=t){
            take=1+solve(i,t-coins[i],dp,coins);
        }
        return dp[i][t]=min(take,nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans=solve(n-1,amount,dp,coins);
        if(ans>=1e9){
            return -1;
        }
        return ans;
    }
};