class Solution {
public:
    int scoreOfParentheses(string s) {
        int c=0;
        for(char k : s){
            if(k=='('){
                c++;
            }
        }
        return c;
    }
};