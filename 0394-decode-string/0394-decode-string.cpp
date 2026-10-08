class Solution {
public:
    string decodeString(string s) {

        stack<int> nums;
        stack<string> st;

        string ans = "";
        int n = 0;

        for(int i = 0; i < s.size(); i++) {

            if(isdigit(s[i])) {

                n = n * 10 + (s[i] - '0');
            }

            else if(s[i] == '[') {

                st.push(ans);
                nums.push(n);

                ans = "";
                n = 0;
            }

            else if(s[i] == ']') {

                string temp = ans;

                ans = st.top();
                st.pop();

                int times = nums.top();
                nums.pop();

                while(times--) {
                    ans += temp;
                }
            }

            else {

                ans += s[i];
            }
        }

        return ans;
    }
};