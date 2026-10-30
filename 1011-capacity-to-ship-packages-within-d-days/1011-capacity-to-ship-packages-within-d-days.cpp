class Solution {
public:
    int funct(vector<int>&weights,int mid){
        int days=1;
        int load=0;
        for(int i=0;i<weights.size();i++){
            if(weights[i]+load>mid){
                days++;
                load=weights[i];
            }
            else{
                load+=weights[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=weights[0];
        int high=0;
        for(int i=0;i<weights.size();i++){
            high+=weights[i];
            low=max(low,weights[i]);
        }
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int d=funct(weights,mid);
            if(d<=days){
                high=mid-1;
                ans=mid;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};