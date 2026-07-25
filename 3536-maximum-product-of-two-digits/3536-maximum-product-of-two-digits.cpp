class Solution {
public:
    int maxProduct(int n) {
        string str=to_string(n);
        int ans=0;
        sort(str.begin(),str.end());
        reverse(str.begin(),str.end());
        
        ans=(str[0]-'0')*(str[1]-'0');
        return ans;

    }
};