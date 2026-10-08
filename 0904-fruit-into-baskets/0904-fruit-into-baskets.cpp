class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int maxlen=0;
        int left=0;
        int right=0;
        map<int,int>mpp;
        while(right<fruits.size()){
            mpp[fruits[right]]++;
            if(mpp.size()>2){
                mpp[fruits[left]]--;
                
                if(mpp[fruits[left]]==0){
                    mpp.erase(fruits[left]);
                }
                left++;
            }
            if(mpp.size()<=2){
                maxlen=max(maxlen,right-left+1);
            }
            right++;
        }
        return maxlen;
    }
};