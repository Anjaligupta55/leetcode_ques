class Solution {
public:
    string minWindow(string s, string t) {
        int left=0;
        int start=0;
        int right=0;
        int minlen=INT_MAX;
        unordered_map<char,int>hp;
        for(int i=0;i<t.size();i++){
            hp[t[i]]++;
        }
        int req=t.size();
        unordered_map<char,int>window;
        for(right=0;right<s.size();right++){
            if(hp.find(s[right])!=hp.end()){
                window[s[right]]++;
                if(window[s[right]]<=hp[s[right]]){
                    req--;
                }
            }
            
            while(req==0){
                if(right-left+1<minlen){
                    minlen=right-left+1;
                    start=left;
                }
                if(hp.find(s[left])!=hp.end()){
                    window[s[left]]--;
                    if(window[s[left]]<hp[s[left]]){
                        req++;
                    }
                }
                left++;
            }
        }
        if(minlen==INT_MAX){
            return "";
        }
        return s.substr(start,minlen);
    }
};