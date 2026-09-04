class Solution {
public:
    int solve(int i,vector<int>&nums,vector<int>&dp){
        if(i>=nums.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int pick=nums[i]+solve(i+2,nums,dp);
        int notpick=0+solve(i+1,nums,dp);
        dp[i]=max(pick,notpick);
        return dp[i];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        int ans=solve(0,nums,dp);
        return ans;
        
    }
};