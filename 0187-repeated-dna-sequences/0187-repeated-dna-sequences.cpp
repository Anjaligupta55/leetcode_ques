class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string>ans;
        unordered_map<string,int>mp;
        for(int i=0;i+10<=s.size();i++){
            string sub=s.substr(i,10);
            mp[sub]++;
            if(mp[sub]==2){
                ans.push_back(sub);
            }
        }
        return ans;

    }
};