class Solution {
public:
    int minOperations(string s) {
        int ans=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]!='a'){
                ans=max(ans,26-(s[i]-'a'));
            }
        }
        return ans;
    }
};