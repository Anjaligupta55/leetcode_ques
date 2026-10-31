class Solution {
public:
    bool cansplit(vector<int>&nums,int k,int mid){
        int c=1;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]>mid){
                c++;
                sum=nums[i];
            }
            else{
                sum+=nums[i];
            }
        }
        if(c<=k){
            return true;
        }
        return false;
    }
    int splitArray(vector<int>& nums, int k) {
        int low=nums[0];
        int high=0;
        for(int i :nums){
            low=max(low,i);
            high+=i;
        }
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(cansplit(nums,k,mid)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};