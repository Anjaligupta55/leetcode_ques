class Solution {
public:
    int func(vector<int>&nums,int goal){
        if(goal<0){
            return 0;
        }
        int l=0,r=0,c=0;
        int sum=0;
        while(r<nums.size()){
            sum+=nums[r];
            while(sum>goal){
                sum-=nums[l];
                l++;
            }
            c+=(r-l+1);
            r++;
        }
        return c;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return func(nums,goal)-func(nums,goal-1);
    }
};