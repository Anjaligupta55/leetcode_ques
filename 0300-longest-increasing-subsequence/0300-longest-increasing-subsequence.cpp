class Solution {
public:
    int solve(int i,vector<int>& nums,vector<int>& dp){
        if(dp[i]!=-1){
            return dp[i];
        }
        int ans=1;
        for(int j=i+1;j<nums.size();j++){
            if(nums[j]>nums[i]){
                ans=max(ans,1+solve(j,nums,dp));
            }
        }
        dp[i]=ans;
        return dp[i];
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        int ans=1;
        for(int i=0;i<nums.size();i++){
            ans=max(ans,solve(i,nums,dp));
        }
        return ans;
    }
};