class Solution {
public:
    int solve(vector<int>&dp,int i, vector<int>&nums){
        if(i>=nums.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int take=nums[i]+solve(dp,i+2,nums);
        int nottake=solve(dp,i+1,nums);
        return dp[i]=max(take,nottake);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return solve(dp,0,nums);
    }
};