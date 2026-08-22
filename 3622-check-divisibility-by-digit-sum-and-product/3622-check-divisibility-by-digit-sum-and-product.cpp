class Solution {
public:
    bool checkDivisibility(int n) {
        int s=0;
        int f=1;
        int m=n;
        while(n>0){
            int d=n%10;
            s+=d;
            f*=d;
            n/=10;
        }
        int p=s+f;
        if(m%p==0){
            return true;
        }
        return false;
    }
};