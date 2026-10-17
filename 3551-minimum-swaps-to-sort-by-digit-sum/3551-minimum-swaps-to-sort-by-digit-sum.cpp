class Solution {
public:
    static int getsum(int x){
        int sum=0;
        while(x>0){
            sum+=(x%10);
            x/=10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        vector<int>aftersort(nums);
        
        auto lambda=[](int n1,int n2){
            int d1=getsum(n1);
            int d2=getsum(n2);
            if(d1!=d2){
                return d1<d2;
            }
            return n1<n2;
        };
        sort(aftersort.begin(),aftersort.end(),lambda);
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]=i;
        }
        for(int i=0;i<n;i++){
            int curr=nums[i];
            int expect=aftersort[i];
            if(curr==expect){
                continue;
            }
            int idx=mp[expect];
            nums[i]=expect;
            nums[idx]=curr;
            mp[expect]=i;
            mp[curr]=idx;
            ans++;
        }
        return ans;
    }
};