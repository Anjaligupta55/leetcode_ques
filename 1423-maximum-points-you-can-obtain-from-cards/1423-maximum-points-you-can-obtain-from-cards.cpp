class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int m = n - k;
        int sum = 0;
        for(int i = 0; i < m; i++) {
            sum += cardPoints[i];
        }
        int mini = sum;
        for(int i = m; i < n; i++) {
            sum += cardPoints[i];
            sum -= cardPoints[i - m];
            mini = min(mini, sum);
        }
        int total = 0;
        for(int i = 0; i < n; i++) {
            total += cardPoints[i];
        }
        return total-mini;
    }
};