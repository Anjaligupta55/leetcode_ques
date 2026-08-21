class Solution {
public:
    void solve(int n,int l,int r,vector<string>&ans,string s){
        if(s.size()==2*n){
            ans.push_back(s);
            return;
        }
        if(l<n){
            s+='(';
            solve(n,l+1,r,ans,s);
            s.pop_back();
        }
        if(r<l){
            s+=')';
            solve(n,l,r+1,ans,s);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {

        string s="";
        vector<string>ans;
        solve(n,0,0,ans,s);
        return ans;
        
        
    }
};