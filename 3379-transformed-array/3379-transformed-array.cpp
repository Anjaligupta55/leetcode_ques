class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int x=nums.size();
        vector<int>result(x);
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                int n=nums[i];
                int p=i;
                while(n--){
                    p=(p+1)%x;
                    // p++;
                }
                result[i]=nums[p];
            }
            else if(nums[i]<0) {
                int n=abs(nums[i]);
                int p=i;
                while(n--){
                    p=(p-1+x)%x;
                    // p--;
                }
                result[i]=nums[p];
            }
            else{
                result[i]=nums[i];
            }
        }
        return result;
    }
};