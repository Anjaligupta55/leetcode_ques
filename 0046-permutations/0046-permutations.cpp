class Solution {
public:
    void solve(int n,vector<int>&nums,vector<vector<int>>&ans){
        if(n==nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=n;i<nums.size();i++){
            swap(nums[n],nums[i]);
            solve(n+1,nums,ans);
            swap(nums[n],nums[i]);
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>arr;
        solve(0,nums,ans);
        return ans;
    }
};