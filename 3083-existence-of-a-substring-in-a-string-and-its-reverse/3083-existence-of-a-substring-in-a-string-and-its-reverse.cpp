class Solution {
public:
    bool isSubstringPresent(string s) {
        for(int i=0;i<s.size()-1;i++){
            string a=s.substr(i,2);
            string b="";
            b+=a[1];
            b+=a[0];
            if(s.find(b)!=string::npos){
                return true;
            }
        }
        return false;
    }
};