class Solution {
public:
    void dfs(int node ,vector<vector<int>>&adj,vector<int>&vis,vector<int>&comp){
        vis[node]=1;
        comp.push_back(node);
        for(int x :adj[node]){
            if(!vis[x]){
                dfs(x,adj,vis,comp);
            }
        }
    }
    bool iscomplete(vector<int>&comp,vector<vector<int>>&adj){
        int k=comp.size();
        for(int x: comp){
            if(adj[x].size()!=k-1){
                return false;
            }
        }
        return true;
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> vis (n,0);
        vector<vector<int>>adj (n);
        for(int i=0;i<edges.size();i++){
            int a=edges[i][0];
            int b=edges[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int c=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                vector<int>comp;
                dfs(i,adj,vis,comp);
                if(iscomplete(comp,adj)){
                    c++;
                }
                
            }
        }
        return c;

        
    }
};