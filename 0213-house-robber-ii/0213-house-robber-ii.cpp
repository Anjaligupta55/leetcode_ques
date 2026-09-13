class Solution {
public:
    int solve(int i,vector<int>& arr,vector<int>& dp){
        if(i>=arr.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int take=arr[i]+solve(i+2,arr,dp);
        int nottake=solve(i+1,arr,dp);
        dp[i]=max(take,nottake);
        return dp[i];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        vector<int>arr1,arr2;
        for(int i=0;i<n;i++){
            if(i!=0){
                arr1.push_back(nums[i]);
            }
            if(i!=n-1){
                arr2.push_back(nums[i]);
            }
        }
        vector<int>dp1(n-1,-1);
        vector<int>dp2(n-1,-1);
        int ans=max(solve(0,arr1,dp1),solve(0,arr2,dp2));
        return ans;
    }
};