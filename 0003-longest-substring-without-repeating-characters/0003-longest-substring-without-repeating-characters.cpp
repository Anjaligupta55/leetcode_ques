class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string k="";
        int left=0;
        int right=0;
        int ans=0;
        int n=s.size();
        while(right<n){
            while(k.find(s[right]) != string::npos){
                k.erase(k.begin());
                left++;
            }
           
                k+=s[right];
                right++;
                ans=max(ans,(int)k.size());
            
           

        }
        return ans;
    }
};