class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int>hp;
        int left=0;
        int right=0;
        int len;
        int maxlen=0;
        int n=s.size();
        while(right<n){
            if(hp.find(s[right])!=hp.end()){
                if(hp[s[right]]>=left){
                    left=hp[s[right]]+1;
                }
            }
            len=right-left+1;
            maxlen=max(maxlen,len);
            hp[s[right]]=right;
            right++;
        }
        return maxlen;
    }
    
};