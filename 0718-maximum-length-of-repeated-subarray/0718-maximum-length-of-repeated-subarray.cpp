
class Solution {
public:
    int dp[1001][1001];
    int solve(vector<int>& nums1, vector<int>& nums2, int i, int j) {
        if (i == nums1.size() || j == nums2.size()) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (nums1[i] == nums2[j]) {
            return dp[i][j]=1+solve(nums1, nums2, i+1, j+1);
        }
        return dp[i][j] = 0;
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        memset(dp, -1, sizeof(dp));
        int ans = 0;
        for (int i= 0;i<nums1.size();i++) {
            for (int j = 0; j < nums2.size(); j++) {
                ans = max(ans, solve(nums1, nums2, i, j));
            }
        }
        return ans;
    }
};
