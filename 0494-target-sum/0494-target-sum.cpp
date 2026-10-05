class Solution {
public:
    int solve(int i,int s,int target,vector<int>&nums,vector<vector<int>>&dp){
         if(i == 0) {

            int ans = 0;

            if(s + nums[0] == target)
                ans++;

            if(s - nums[0] == target)
                ans++;

            return ans;
        }
        if(dp[i][s+20000]!=-1){
            return dp[i][s+20000];
        }
        int p=solve(i-1,s+nums[i],target,nums,dp);
        int m=solve(i-1,s-nums[i],target,nums,dp);
        return dp[i][s+20000]=p+m;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        if(n==1 && nums[0]==0 && target==0){
            return 2;
        }
        vector<vector<int>>dp(n,vector<int>(40001,-1));
        int ans=solve(n-1,0,target,nums,dp);
        return ans;
    }
};