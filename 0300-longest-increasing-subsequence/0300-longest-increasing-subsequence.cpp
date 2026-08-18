class Solution {
public:
    // int solve(int i,vector<int>&nums,vector<int>&dp){
    //     if(i==nums.size()){
    //         return 1;
    //     }
    //     if(dp[i]!=-1){
    //        return dp[i];
    //     }
    //     dp[i]=max(dp[i],solve(i+1,nums,dp));
    //     return dp[i];
    // }
    int lengthOfLIS(vector<int>& nums) {
        // int ans=0;
        // int n=nums.size();
        // vector<int>dp(n+1,-1);
        // dp[0]=1;
        // ans=solve(0,nums,dp);
        // return ans;
        int ans=0;
        int n=nums.size();
        vector<int>dp(n,1);
        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(nums[i]<nums[j]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
            ans=max(ans,dp[i]);
        }
        return ans;
        
    }
};