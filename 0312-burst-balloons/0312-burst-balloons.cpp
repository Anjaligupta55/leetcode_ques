class Solution {
public:
    int solve(int left,int right,vector<int>&nums,vector<vector<int>>& dp){
        if(left+1==right){
            return 0;
        }
        if(dp[left][right]!=-1){
            return dp[left][right];
        }
        int ans=0;
        for(int k=left+1;k<right;k++){
            int c=solve(left,k,nums,dp)+solve(k,right,nums,dp)+nums[left]*nums[k]*nums[right];
            ans=max(ans,c);
        }
        return dp[left][right]=ans;

    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int ans=solve(0,nums.size()-1,nums,dp);
        return ans;
    }
};