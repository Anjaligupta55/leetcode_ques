class Solution {
public:
    int solve(int i,int n,vector<int>&dp,vector<int>&nums){
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int take=nums[i]+solve(i+2,n,dp,nums);
        int skip=solve(i+1,n,dp,nums);
        dp[i]=max(take,skip);
        return dp[i];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        solve(0,n,dp,nums);
        return dp[0];
        // int prev1 = 0;  
        // int prev2 = 0;  

        // for (int num : nums) {
        //     int temp = max(prev1, prev2 + num);
        //     prev2 = prev1;
        //     prev1 = temp;
        // }

        // return prev1;
    }
};
