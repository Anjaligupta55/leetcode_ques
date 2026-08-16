class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum=nums[0];
        int c=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]+1){
                sum+=nums[i];
            }
            else{
                break;
            }
        }
        unordered_set<int>s;
        for(int i : nums){
            s.insert(i);
        }
        while(s.count(sum)){
            sum++;
        }
        return sum;


    }
};