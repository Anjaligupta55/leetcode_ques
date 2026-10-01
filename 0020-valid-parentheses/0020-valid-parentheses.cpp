class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(char ct : s){
            if(ct=='(' || ct=='{' || ct=='['){
                st.push(ct);
            }
            else{
                if(st.empty()){
                    return false;
                }
                if(ct==')' && st.top()!='('){
                    return false;
                }
                if(ct=='}' && st.top()!='{'){
                    return false;
                }
                if(ct==']' && st.top()!='['){
                    return false;
                }
                st.pop();
            }
        }
        if(st.empty()){
            return true;
        }
        return false;
    }
};