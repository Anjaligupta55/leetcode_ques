class Solution {
public:
   static bool cmp(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0])
            return a[1] > b[1];  
        return a[0] < b[0];
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        int ans=0;
        sort(intervals.begin(),intervals.end(),cmp);
        int maxend=-1;
        for(auto p : intervals){
            int s=p[0];
            int e=p[1];
            if(maxend<e){
                ans++;
                maxend=e;
            }
        }
        return ans;
    }
};