class Solution {
public:
    void solve(int i,vector<int>& nums,vector<vector<int>>&ans,vector<int>&arr){
        if(i==nums.size()){
            ans.push_back(arr);
            return;
        }
        arr.push_back(nums[i]);
        solve(i+1,nums,ans,arr);
        arr.pop_back();
        solve(i+1,nums,ans,arr);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>arr;
        solve(0,nums,ans,arr);
        return ans;
    }
};