class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string ans="";
        unordered_map<string,string>hp;
        for(auto &p : knowledge){
            hp[p[0]]=p[1];
        }
        string key="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                key="";
                i++;
                while(s[i]!=')'){
                    key+=s[i];
                    i++;
                }
                if(hp.find(key)!=hp.end()){
                    ans+=hp[key];
                }
                else{
                    ans+='?';
                }
            }
            else{
                ans+=s[i];
            }
        }
        return ans;
    }
};