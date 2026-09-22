class Solution {
public:
    int x[15];
    int c=0;
    bool place(int k,int i){
        for(int j=0;j<=k-1;j++){
            if(x[j]==i){
                return false;
            }
            else if(abs(x[j]-i)==abs(j-k)){
                return false;
            }
        }
        return true;
    }
    void nqueen(int k,int n){
        for(int i=0;i<n;i++){
            if(place(k,i)){
                x[k]=i;
                if(k==n-1){
                    c++;
                }
                else{
                    nqueen(k+1,n);
                }
            }
        }
    }
    int totalNQueens(int n) {
        c=0;
        nqueen(0,n);
        return c;
    }
};