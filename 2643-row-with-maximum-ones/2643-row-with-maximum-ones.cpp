class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        vector<int>ans;
        int c=0;
        int index=0;
        for(int i=0;i<mat.size();i++){
            vector<int>p=mat[i];
            int s=0;
            for(int j=0;j<p.size();j++){
                if(p[j]==1){
                    s++;
                }
            }
            if(s>c){
                c=s;
                index=i;
            }
        }
        ans.push_back(index);
        ans.push_back(c);
        return ans;
    }
};