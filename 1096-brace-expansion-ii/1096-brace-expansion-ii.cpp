class Solution {
public:
    int index=0;
    set<string>solve(string s){
        set<string>result;
        set<string> current;
        current.insert("");
        while(index< s.length() && s[index]!='}'){
            if(s[index]==','){
                result.insert(current.begin(),current.end());
                current.clear();
                current.insert("");
                index++;
            }
            else{
                set<string>part;
                if(s[index]=='{'){
                    index++;
                    part=solve(s);
                    index++;
                }
                else{
                    part.insert(string(1,s[index]));
                    index++;
                }
                set<string>temp;
                for(string a : current){
                    for(string b: part){
                        temp.insert(a+b);
                    }
                }
                current= temp;
            }
        }
        result.insert(current.begin(),current.end());
        return result;
    }
    vector<string> braceExpansionII(string expression) {
        index = 0;
        set<string> result = solve(expression);
        vector<string> ans(result.begin(), result.end());
        sort(ans.begin(), ans.end());
        return ans;
    }
};