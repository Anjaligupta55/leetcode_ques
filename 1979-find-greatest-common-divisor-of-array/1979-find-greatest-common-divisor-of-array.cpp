class Solution {
public:
    int findGCD(vector<int>& nums) {
        int m=*min_element(nums.begin(),nums.end());
        int l=*max_element(nums.begin(),nums.end());
        while(m!=0){
            int temp=m;
            m=l%m;
            l=temp;
        }
        return l;
    }
};