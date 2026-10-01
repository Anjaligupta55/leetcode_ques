class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int>s;
        for(int i : nums){
            s.insert(i);
        }
        vector<int>arr;
        for(auto & i : s){
            arr.push_back(i);
        }
        sort(arr.begin(),arr.end());
        if(arr.size()>=3){
            return arr[arr.size()-3];
        }
        return arr[arr.size()-1];
    }
};