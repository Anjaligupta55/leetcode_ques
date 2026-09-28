class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int count=0;
        int sum=0;
        for(int i=0;i<k;i++){
            sum+=arr[i];
        }
        int aveg=sum/k;
        if(aveg>=threshold){
            count++;
        }
        for(int i=k;i<arr.size();i++){
            sum+=arr[i];
            sum-=arr[i-k];
            int avg=sum/k;
            if(avg>=threshold){
                count++;
            }
        }
        return count;
    }
};