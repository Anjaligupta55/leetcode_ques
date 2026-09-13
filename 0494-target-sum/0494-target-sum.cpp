class Solution {
public:
    int solve(int i,int sum,vector<int>& nums,int target,vector<vector<int>>&dp){
        if(i==nums.size() ){
            if(target==sum){
                return 1;
            }
            return 0;
        }
        if(dp[i][sum+20000]!=-1){
            return dp[i][sum+20000];
        }
        int p=solve(i+1,sum+nums[i],nums,target,dp);
        int m=solve(i+1,sum-nums[i],nums,target,dp);
        dp[i][sum+20000]=p+m;
        return dp[i][sum+20000];

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
         vector<vector<int>> dp(n, vector<int>(40001, -1));
        int ans=solve(0,0,nums,target,dp);
        return ans;
    }
};