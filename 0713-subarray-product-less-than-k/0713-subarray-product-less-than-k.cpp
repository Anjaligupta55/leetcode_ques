class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1){
            return 0;
        }
        int c=0;
        int n=nums.size();
        int l=0;
        int r=0;
        int p=1;
        while(r<n){
            p*=nums[r];
            while(p>=k){
                p/=nums[l];
                l++;
            }
            if(p<k){
                c+=r-l+1;
            }
            r++;
        }
        return c;
    }
};