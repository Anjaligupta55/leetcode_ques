class Solution {
public:
    int mySqrt(int x) {
        if(x==0){
            return 0;
        }
        int ans=-1;
        int l=1;
        int h=x;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(mid==x/mid){
                ans=mid;
                break;
            }
            else if(mid>x/mid){
                h=mid-1;
            }
            else{
                ans=mid;
                l=mid+1;
            }
        }
        return ans;
    }
};