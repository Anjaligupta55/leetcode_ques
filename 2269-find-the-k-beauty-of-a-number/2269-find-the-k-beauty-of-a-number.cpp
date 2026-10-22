class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string h=to_string(num);
        int n=h.size();
        int l=0;
        int r=0;
        string s="";
        int c=0;
        while(r<n){
            s+=h[r];
            if(s.size()==k){
                int w=stoi(s);
                if(w!=0 && num%w==0){
                    c++;
                }
                s.erase(0, 1);
                l++;
            }
            r++;
        }
        return c;
    }
};