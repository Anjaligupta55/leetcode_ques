class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int ans=k;
        unordered_map<int,int>hp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            hp[nums[i]]=i;
        }
        while(hp.find(ans) != hp.end()) {
            ans += k;
        }
        return ans;
    }
};