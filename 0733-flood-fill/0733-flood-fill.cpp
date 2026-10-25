class Solution {
public:
    int m;
    int n;
    void dfs(vector<vector<int>>& image,int i,int j,int color,int t){
        if(i>=m || i<0 || j>=n || j<0 || image[i][j]!=t){
            return;
        }
        image[i][j]=color;
        dfs(image,i,j-1,color,t);
        dfs(image,i,j+1,color,t);
        dfs(image,i-1,j,color,t);
        dfs(image,i+1,j,color,t);

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        m=image.size();
        n=image[0].size();
        int t=image[sr][sc];
        if(t==color){
            return image;
        }
        dfs(image,sr,sc,color,t);
        return image;
    }
};