class Solution {
public:
    int func(vector<int>&nums ,int k){
        if(k<0){
            return 0;
        }
        map<int,int>mp;
        int c=0;
        int l=0,r=0;
        while(r<nums.size()){
            mp[nums[r]]++;
            if(mp.size()>k){
                while(mp.size()>k){
                    mp[nums[l]]--;
                    if(mp[nums[l]]==0){
                        mp.erase(nums[l]);
                    }
                    l++;
                }
            }
            c=c+r-l+1;
            r++;
        }
        return c;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return func(nums,k)-func(nums,k-1);
    }
};