class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mx=0;
        for(int i=0;i<nums.size();i++){
            mx=max(mx,nums[i]);
        }
        int ans=0;
        for(int i : nums){
            ans+=mx-i;
        }
        return ans;
    }
};