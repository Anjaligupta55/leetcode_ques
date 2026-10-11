class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int l=0,r=0;
        unordered_map<int,int>mp;
        while(r<nums.size()){
            if(abs(r-l)<=k && mp.find(nums[r])!=mp.end() ){
                return true;
            }
            mp[nums[r]]++;
            if(r-l>=k){
                mp[nums[l]]--;
                if(mp[nums[l]]==0){
                    mp.erase(nums[l]);
                }
                l++;
            }
            r++;
        }
        return false;
    }
};