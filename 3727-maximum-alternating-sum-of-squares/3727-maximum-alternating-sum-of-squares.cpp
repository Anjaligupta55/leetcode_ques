class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            nums[i]=nums[i]*nums[i];
        }
        sort(nums.begin(),nums.end());
        long long ans=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(i<n/2){
                ans-=nums[i];
            }
            else{
                ans+=nums[i];
            }
        }
        return ans;
    }
};