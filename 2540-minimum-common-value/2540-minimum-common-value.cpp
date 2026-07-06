class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int mini=INT_MAX;
        int n=nums1.size();
        int m=nums2.size();
        int i=0;
        int j=0;
        while(i<n && j<m){
            if(nums1[i]==nums2[j]){
                if(nums1[i]<mini){
                    mini=nums1[i];
                }
                i++;
                j++;
            }
            else if(nums1[i]>nums2[j]){
                j++;
            }
            else{
                i++;
            }
        }
        if(mini!=INT_MAX){
            return mini;
        }
        return -1;
    }
};