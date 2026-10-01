class Solution {
public:
    int solve(int i,int k,vector<int>& dp,vector<int>&nums){
        if(i<0 ){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int ans=0;
        int sum=0;
        for(int j=i;j>=0;j--){
            sum+=nums[j];
            if(sum==k){
                ans++;
            }
        }
        ans+=solve(i-1,k,dp,nums);
        return dp[i]=ans;
    }

    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>dp(n,-1);
        int ans=solve(n-1,k,dp,nums);
        return ans;
    }
};