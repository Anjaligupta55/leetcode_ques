class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int s=nums[0];
        int l=nums[n-1];
        int j=0;
        for(int i=s;i<=l;i++){
            if (j < nums.size() && nums[j] == i) {
                j++; 
            } else {
                ans.push_back(i);
            }
            
        }
        return ans;
        
    }
};