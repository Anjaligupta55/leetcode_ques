class Solution {
public:
    int maximumLengthSubstring(string s) {
        int left=0;
        int ans=0;
        unordered_map<char,int>hp;
        for(int right=0;right<s.size();right++){
            hp[s[right]]++;
            while(hp[s[right]]>2){
                hp[s[left]]--;
                left++;
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};