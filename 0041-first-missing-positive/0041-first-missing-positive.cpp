class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=1;
        set<int>s;
        for(int i :nums){
            s.insert(i);
        }
        while(s.find(n)!=s.end()){
            n++;
        }
        return n;

    }
};