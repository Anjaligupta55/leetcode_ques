class Solution {
public:
    int solve(vector<int>&dp,int i,int n,vector<int>&cost){
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int one=cost[i]+solve(dp,i+1,n,cost);
        int two=cost[i]+solve(dp,i+2,n,cost);
        return dp[i]=min(one,two);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n,-1);
        return min(solve(dp,0,n,cost),solve(dp,1,n,cost));
    }
};