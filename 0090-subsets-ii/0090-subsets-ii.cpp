class Solution {
public:
    void solve(int i, vector<int>& nums,
               vector<int>& arr,
               vector<vector<int>>& ans) {

        ans.push_back(arr);

        for(int j = i; j < nums.size(); j++) {

            if(j > i && nums[j] == nums[j-1]) {
                continue;
            }

            arr.push_back(nums[j]);

            solve(j + 1, nums, arr, ans);

            arr.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> arr;

        solve(0, nums, arr, ans);

        return ans;
    }
};