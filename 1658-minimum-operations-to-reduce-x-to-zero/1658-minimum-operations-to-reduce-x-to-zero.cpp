class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total=0;
        for(int i=0;i<nums.size();i++){
            total+=nums[i];
        }
        int target=total-x;
        if(target==0){
            return nums.size();
        }
        int i=0;
        int sum=0;
        int maxi=-1;
        for(int j=0;j<nums.size();j++){
            sum+=nums[j];
            while(sum>target && i<=j){
                sum-=nums[i];
                i++;
            }
            if(sum==target){
                maxi=max(maxi,j-i+1);
            }
        }
        if(maxi==-1){
            return -1;
        }
        return nums.size()-maxi;
    }
};