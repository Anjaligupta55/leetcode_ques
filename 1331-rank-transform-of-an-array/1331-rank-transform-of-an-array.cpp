class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>num=arr;
        sort(num.begin(),num.end());
        unordered_map<int,int>freq;
        for(auto & p : arr){
            freq[p]++;
        }
        vector<int>ans;
        int j=1;
        for(int i=0;i<num.size();){
            if(freq[num[i]]==1){
                freq[num[i]]=j;
                j++;
                i++;
            }
            else{
                int p=freq[num[i]];
                freq[num[i]]=j;
                j++;
                i=i+p;
            }
        }
        for(int i=0;i<arr.size();i++){
            ans.push_back(freq[arr[i]]);
        }
        return ans;

    }
};