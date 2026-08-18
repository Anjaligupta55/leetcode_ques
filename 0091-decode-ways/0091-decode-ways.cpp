class Solution {
public:
    int solve(int i,string s,vector<int>&dp){
        if(i==s.size()){
            return 1;
        }
        if( s[i]=='0'){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int one=solve(i+1,s,dp);
        int two=0;
        if(i+1<s.size()){
            int num=(s[i]-'0')*10+(s[i+1]-'0');
            if(num>=10 && num<=26){
                two=solve(i+2,s,dp);
            }
        }
        dp[i]=one+two;
        return dp[i];
    }
    int numDecodings(string s) {
        int n=s.size();
        vector<int>dp(n+1,-1);
        int ans=solve(0,s,dp);
        return ans;
    }
};