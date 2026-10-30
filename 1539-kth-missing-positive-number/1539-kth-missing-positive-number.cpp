class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_map<int,int>hp;
        for(int i=0;i<arr.size();i++){
            hp[arr[i]]=i;
        }
        int i=1;
        while(k){
            if(hp.find(i)==hp.end()){
                i++;
                k--;
            }
            else{
                i++;
            }
        }
        return i-1;
    }
};