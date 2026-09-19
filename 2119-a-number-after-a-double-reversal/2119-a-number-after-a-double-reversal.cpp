class Solution {
public:
    bool isSameAfterReversals(int num) {
        int n=num;
        int p=0;
        while(n>0){
            int d=n%10;
            p=p*10+d;
            n=n/10;
        }
        int s=p;
        int k=0;
        while(s>0){
            int d=s%10;
            k=k*10+d;
            s=s/10;
        }
        if(k==num){
            return 1;
        }
        return 0;
    }
};