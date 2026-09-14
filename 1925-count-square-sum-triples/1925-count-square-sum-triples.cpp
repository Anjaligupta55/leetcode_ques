class Solution {
public:
    int countTriples(int n) {
        int ans=0;
        for(int i=1;i<=n;i++){
            int a=i*i;
            for(int j=1;j<=n;j++){
                int b=j*j;
                int c2=a+b;
                int c=sqrt(c2);
                if(c*c==c2 && c<=n){
                    ans++;
                }

            }
        }
        return ans;
    }
};