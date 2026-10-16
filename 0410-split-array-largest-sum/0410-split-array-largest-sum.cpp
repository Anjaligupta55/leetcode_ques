class Solution {
public:
    int split(vector<int>&nums,int mid){
        int p=0;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]<=mid){
                sum+=nums[i];
            }
            else{
                p++;
                sum=nums[i];
            }
        }
        p++;
        return p;
    }
    int splitArray(vector<int>& nums, int k) {
        int sum=0;
        int s=INT_MIN;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            s=max(s,nums[i]);
        }
        int h=sum;
        while(s<=h){
            int mid=s+(h-s)/2;
            int p=split(nums,mid);
            if(p>k){
                s=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        return s;
        
    }
};