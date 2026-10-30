class Solution {
public:
    int funct(vector<int>& bloomDay,int k,int mid){
        int c=0;
        int Noofbouquets=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=mid){
                c++;
            }
            else{
                c=0;
            }
            if(c==k){
                Noofbouquets++;
                c=0;
            }
        }
        return Noofbouquets;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low=0;
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int bouquets=funct(bloomDay,k,mid);
            if(bouquets>=m){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;

    }
};