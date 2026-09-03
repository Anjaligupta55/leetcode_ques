class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int e=INT_MAX;
        int o=INT_MAX;
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]%2==0){
                e=min(e,nums1[i]);
            }
            else{
                o=min(o,nums1[i]);
            }
        }
        if(e==INT_MAX || o==INT_MAX){
            return true;
        }
        if(e>o){
            return true;
        }
        return 0;
    }
};