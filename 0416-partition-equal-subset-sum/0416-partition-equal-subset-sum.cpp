class Solution {
public:
    bool solve(int i,int target,vector<vector<int>>& dp,vector<int>& nums){
        if(target==0){
            return true;
        }
        if(i>=nums.size() || target < 0){
            return false;
        }
         if(dp[i][target] != -1) {
            return dp[i][target];
        }
        bool take=solve(i+1,target-nums[i],dp,nums);
        bool nottake=solve(i+1,target,dp,nums);
        return dp[i][target]=take|| nottake;
    }
    bool canPartition(vector<int>& nums) {
        int totalsum=0;
        for(int i : nums){
            totalsum+=i;
        }
        if(totalsum%2==1){
            return false;
        }
        int target=totalsum/2;
        vector<vector<int>> dp(nums.size(),
                       vector<int>(target + 1, -1));
        int ans=solve(0,target,dp,nums);
        return ans;
    }
};