class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int left=0;
        int right=n-1;
        int maxsum=0;
        int leftsum=0;
        int rightsum=0;
        for(int i=0;i<k;i++){
            leftsum+=cardPoints[i];
        }
        maxsum=leftsum;
        for(int i=k-1;i>=0;i--){
            leftsum-=cardPoints[i];
            rightsum+=cardPoints[right];
            right--;
            maxsum=max(maxsum,leftsum+rightsum);
        }
        return maxsum;
    }
};