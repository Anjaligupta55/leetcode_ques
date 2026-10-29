class Solution {
public:
    bool solve(int i,int target,vector<vector<int>>&dp,vector<int>&nums){
        if(target==0){
            return true;
        }
        if(target<0 || i>=nums.size()){
            return false;
        }
        if(dp[i][target]!=-1){
            return dp[i][target];
        }
        int take=solve(i+1,target-nums[i],dp,nums);
        int nottake=solve(i+1,target,dp,nums);
        return dp[i][target]=take|| nottake;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int totalsum=0;
        for(int i:nums){
            totalsum+=i;
        }
        if(totalsum%2==1){
            return false;
        }
        int target=totalsum/2;
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return solve(0,target,dp,nums);
    }
};