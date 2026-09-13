class Solution {
public:
    int solve(int i,vector<int>&nums,int n,vector<int>&dp){
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int take=nums[i]+solve(i+2,nums,n,dp);
        int nottake=solve(i+1,nums,n,dp);
        dp[i]=max(take,nottake);
        return dp[i];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        int ans=solve(0,nums,n,dp);
        return ans;
    }
};