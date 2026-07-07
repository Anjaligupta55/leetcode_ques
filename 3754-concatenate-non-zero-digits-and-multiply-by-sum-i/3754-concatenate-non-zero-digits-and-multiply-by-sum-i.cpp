class Solution {
public:
    long long sumAndMultiply(int n) {
        string str=to_string(n);
        string p="";
        for(int i=0;i<str.size();i++){
            if(str[i]!='0'){
                p+=str[i];
            }
        }
        long long sum=0;
        long long x=0;
        for(int i=0;i<p.size();i++){
            sum+=p[i]-'0';
            x=x*10+(p[i]-'0');
        }
        long long ans=x*sum;
        return ans;

    }
};