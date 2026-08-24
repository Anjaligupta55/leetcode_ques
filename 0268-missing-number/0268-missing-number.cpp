class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int x=0;
        for(int i :nums){
            x^=i;
        }
        int n=nums.size();
        for(int i=0;i<=n;i++){
            x^=i;
        }
        return x;
    }
};