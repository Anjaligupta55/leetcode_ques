class Solution {
public:
    bool solve(int i,vector<int>&nums,vector<int>& dp , int target){
        if(i==nums.size()){
            for(int j=0;j<dp.size();j++){
                if(dp[j]!=target){
                    return false;
                }
            }
            return true;
        }
        for(int j=0;j<dp.size();j++){
            if(dp[j]+nums[i]<=target){
                dp[j]+=nums[i];
                if(solve(i+1,nums,dp,target)){
                    return true;
                }
                dp[j]-=nums[i];
            }
            if(dp[j] == 0) {
                break;
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n=nums.size();
        int total=0;
        for(int i : nums){
            total +=i;
        }
        if(total%k!=0){
            return false;
        }
        vector<int> dp(k,0);
        int target=total/k;
        sort(nums.rbegin(), nums.rend());
        if(nums[0] > target) {
            return false;
        }
        if(solve(0,nums,dp,target)){
            return true;
        }
        return false;
    }
};