class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
       
        int n=matrix.size();
        vector<int>a=matrix[0];
        int m=a.size();
         vector<vector<int>>arr(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                arr[j][i]=matrix[i][j];
            }
        }
        vector<vector<int>>res(n,vector<int>(m));
        int k=0;
        int l=0;
        for(int i=0;i<n;i++){
            l=0;
            for(int j=m-1;j>=0;j--){
                res[k][l++]=arr[i][j];
            }
            k++;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                matrix[i][j]=res[i][j];
            }
        }

        

    }
};