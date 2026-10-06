class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans=0;
        int b=0;
        stack<char>st;
        for(char c : s){
            if(c=='('){
                st.push('(');
            }
            else{
                if(!st.empty() && st.top()=='('){
                    st.pop();
                }
                else{
                    b++;
                }
            }
        }
        while(!st.empty()){
            b++;
            st.pop();
        }

        return b;
    }
};