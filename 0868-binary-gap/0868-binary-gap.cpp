class Solution {
public:
    int binaryGap(int n) {
        string str="";
        while(n>0){
            int d=n%2;
            str+=to_string(d);
            n=n/2;
        }
        reverse(str.begin(),str.end());
        int ans=0;
        int last1=-1;
        for(int i=0;i<str.size();i++){
            if(str[i]=='1' ){
                if(last1!=-1){
                    ans=max(ans,i-last1);
                }
                last1=i;
            }
            
        }
        return ans;
        
    }
};