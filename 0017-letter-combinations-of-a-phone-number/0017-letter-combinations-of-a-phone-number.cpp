class Solution {
public:
    void solve(int i,int n,vector<string>&ans, unordered_map<int,string>& mp,string& s,string digits){
        if(i==n){
            ans.push_back(s);
            return;
        }
        string temp=mp[digits[i]-'0'];
        for(int j=0;j<temp.size();j++){
            s+=temp[j];
            solve(i+1,n,ans,mp,s,digits);
             s.pop_back();
        }
       
    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        unordered_map<int,string>mp={{2,"abc"},{3,"def"},{4,"ghi"},{5,"jkl"},{6,"mno"},{7,"pqrs"},{8,"tuv"},{9,"wxyz"}};
        string s;
        solve(0,digits.size(),ans,mp,s,digits);
        return ans;
    }
};