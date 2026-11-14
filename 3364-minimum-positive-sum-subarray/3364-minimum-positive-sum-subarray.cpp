class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++){
            int sum=0;
            int j=i;
            int k=0;
            while(j<nums.size() && k<r){
                sum+=nums[j];
                j++;
                k++;
                if(k>=l && r<=r && sum>0){
                    ans=min(ans,sum);
                }
            }
        }
        if( ans==INT_MAX) return -1;
        return ans;
    }
};