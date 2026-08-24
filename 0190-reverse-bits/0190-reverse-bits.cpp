class Solution {
public:
    int reverseBits(int n) {
        int ans=0;
        for(int i=0;i<32;i++){
            int x=n&1; //lst bit
            ans=(ans<<1)|x; //set 
            n=n>>1;
        }
        return ans;
    }
};