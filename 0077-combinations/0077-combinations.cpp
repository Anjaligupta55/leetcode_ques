class Solution {
public:
    void solve(int i,int n,int k,vector<int>& arr, vector<vector<int>>& ans){
        if(arr.size()==k){
            ans.push_back(arr);
            return;
        }
        for(int j=i;j<=n;j++){
           arr.push_back(j);
           solve(j+1,n,k,arr,ans);
           arr.pop_back();
        }

    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>arr;
        solve(1,n,k,arr,ans);
        return ans;
        
    }
};