class Solution {
public:
    int hammingDistance(int x, int y) {
        int c=0;
        while(x>0 || y>0){
            if(((x&1 )==0 && (y&1)==1 ) || ((x&1 )==1 && (y&1)==0 )){
                c++;
            }
            x=x>>1;
            y=y>>1;
        }
        return c;
    }
};