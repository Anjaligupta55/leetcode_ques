class Solution {
public:
    bool hasAlternatingBits(int n) {
        int lastdig=-1;
        while(n>0){
            int d=n%2;
            if(lastdig==d){
                return false;
            }
            n=n/2;
            lastdig=d;
        }
        return true;
        
    }
};