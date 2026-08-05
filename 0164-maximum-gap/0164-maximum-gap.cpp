class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size()<2){
            return 0;
        }
        vector<int>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++){
            int j = i + 1;
            ans.push_back(abs(nums[i]-nums[j]));
        }
        sort(ans.begin(),ans.end());
        return ans[ans.size()-1];
    }
};