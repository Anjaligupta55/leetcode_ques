class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int p=INT_MAX;
        int n=nums.size();
        int ans=-1;
        for(int i=0;i<n;i++){
            int m=*max_element(nums.begin(),nums.begin()+i+1);
            int s=*min_element(nums.begin()+i,nums.end());
           
            // if((m-s)<=k){
            //     if(p>(m-s)){
            //         p=m-s;
            //         ans=i;
            //     }
                
            // }
            if((m - s) <= k){
                return i;
            }
        }
        return -1;
    }
};