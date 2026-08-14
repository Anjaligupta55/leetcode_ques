class Solution {
public:
    int trap(vector<int>& arr) {
        int n=arr.size();
        vector<int>left(n,0);
        vector<int>right(n,0);
        left[0]=arr[0];
        int h=arr[0];
        right[n-1]=arr[n-1];
        int hr=arr[n-1];
        for(int i=1;i<n;i++){
            if(arr[i]<h){
                left[i]=h;
            }
            else{
                left[i]=arr[i];
                h=arr[i];
            }
        }
        for(int i=n-2;i>=0;i--){
            if(arr[i]<hr){
                right[i]=hr;
            }
            else{
                right[i]=arr[i];
                hr=arr[i];
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int w=min(right[i],left[i])-arr[i];
            ans+=w;
        }
        return ans;
        
    }
};