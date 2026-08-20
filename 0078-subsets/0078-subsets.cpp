class Solution {
public:
    void solve(int i,vector<int>&nums,vector<vector<int>>&ans,vector<int>&curr){
        if(i==nums.size()){
            ans.push_back(curr);
            return ;
        }
        curr.push_back(nums[i]);
        solve(i+1,nums,ans,curr);
        curr.pop_back();
        solve(i+1,nums,ans,curr);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>curr;
        solve(0,nums,ans,curr);
        return ans;
    }
};