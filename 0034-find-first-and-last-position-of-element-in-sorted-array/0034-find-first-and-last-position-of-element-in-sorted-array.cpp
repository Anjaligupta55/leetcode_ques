class Solution {
public:
    int firstocc(vector<int>&nums,int target){
        int low=0;
        int high=nums.size()-1;
        int first=-1;
        while(low<=high){
            int mid=(high-low)/2+low;
            if(nums[mid]==target){
                first=mid;
                high=mid-1;
            }
            else if(nums[mid]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return first;
    }
    int lastocc(vector<int>&nums,int target){
        int low=0;
        int high=nums.size()-1;
        int last=-1;
        while(low<=high){
            int mid=(high-low)/2+low;
            if(nums[mid]==target){
                last=mid;
                low=mid+1;
            }
            else if(nums[mid]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return last;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int f=firstocc(nums,target);
        if(f==-1){
            return {-1,-1};
        }
        int l=lastocc(nums,target);
        return {f,l};
    }
};