class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hp;
        for(int i = 0; i < nums.size(); i++){
            hp[nums[i]] = i;
        }
        for(int i = 0; i < nums.size(); i++){
            int n = nums[i];
            int m = target - n;
            if(hp.find(m) != hp.end() && hp[m] != i){
                return {i, hp[m]};
            }
        }
        return {};
    }
};