class Solution {
public:
    int countGoodSubstrings(string s) {
        map<char,int>mpp;
        int l=0;
        int r=0;
        int n=s.size();
        string ans="";
        int c=0;
        while(r<n){
            mpp[s[r]]++;
            if(r-l+1==3){
                if(mpp.size()==3 ){
                    c++;
                }
            
            mpp[s[l]]--;
            if(mpp[s[l]]==0){
                mpp.erase(s[l]);
            }
            l++;
            }
            r++;
        }
        return c;
    }
};