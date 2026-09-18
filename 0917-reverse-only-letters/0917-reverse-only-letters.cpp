class Solution {
public:
    string reverseOnlyLetters(string s) {
        int l=0;
        int r=s.size()-1;
        while(l<=r){
            if((s[l]>='a' && s[l]<='z') || (s[l]>='A' && s[l]<='Z')){
                if((s[r]>='a' && s[r]<='z') || (s[r]>='A' && s[r]<='Z')){
                    swap(s[r],s[l]);
                    r--;
                    l++;
                }
                else{
                    r--;
                }
            }
            else{
                l++;
            }
        }
        return s;
    }
};