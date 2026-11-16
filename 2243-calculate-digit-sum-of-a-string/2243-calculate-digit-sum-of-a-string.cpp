class Solution {
public:
    string digitSum(string s, int k) {
        while(s.size()>k){
            string l="";
            for(int i=0;i<s.size();i+=k){
                int j=k;
                int m=i;
                int n=0;
                while(j-- && m<s.size()){
                    n+=(s[m++]-'0');
                }
                l+=to_string(n);
                n=0;
                
            }
            s=l;
        }
        return s;
    }
};