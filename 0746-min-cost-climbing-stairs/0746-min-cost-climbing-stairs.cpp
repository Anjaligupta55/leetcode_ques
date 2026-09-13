class Solution {
public:
    int solve(int i,vector<int>& dp,vector<int>&cost){
        if(i>=cost.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int onestep=cost[i]+solve(i+1,dp,cost);
        int twostep=cost[i]+solve(i+2,dp,cost);
        dp[i]=min(onestep,twostep);
        return dp[i];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n,-1);
        int ans=min(solve(0,dp,cost),solve(1,dp,cost));
        return ans;
    }
};