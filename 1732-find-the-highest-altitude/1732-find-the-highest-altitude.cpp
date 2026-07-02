class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
        vector<int>arr(n+1);
        arr.push_back(0);
        
        for(int i=0;i<n;i++){
            int r=arr[arr.size()-1]+gain[i];
            arr.push_back(r);
        }
        return *max_element(arr.begin(),arr.end());
        
    }
};