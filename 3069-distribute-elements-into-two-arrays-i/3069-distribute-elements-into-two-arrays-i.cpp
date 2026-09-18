class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int>ans,arr1,arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        for(int i=2;i<nums.size();i++){
            int a1=arr1.back();
            int a2=arr2.back();
            if(a1>a2){
                arr1.push_back(nums[i]);
            }
            else{
                arr2.push_back(nums[i]);
            }
        }
        ans.insert(ans.end(),arr1.begin(),arr1.end());
        ans.insert(ans.end(),arr2.begin(),arr2.end());
        return ans;
    }
};