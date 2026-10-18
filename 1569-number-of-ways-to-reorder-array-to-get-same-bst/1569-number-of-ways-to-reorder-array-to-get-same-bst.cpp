class Solution {
int dp[1001][1001], MOD = 1e9 + 7;
void precompute() {
    for(int i = 0; i < 1001; i++) {
        dp[i][0] = dp[0][i] = 1;
    }
    for(int i = 1; i < 1001; i++) {
        for(int j = 1; j < 1001; j++) {
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
        }
    }
}
int divideAndConquer(vector<int>& arr) {
    if(!arr.size()) return 1;
    vector<int> s, g;
    for(int i = 1; i < arr.size(); i++) {
        if(arr[i] < arr[0]) s.push_back(arr[i]);
        else g.push_back(arr[i]);
    }
    return 1LL * dp[s.size()][g.size()] * divideAndConquer(s) % MOD * divideAndConquer(g) % MOD;
}
public:
    int numOfWays(vector<int>& nums) {
        precompute();
        return (divideAndConquer(nums) - 1 + MOD) % MOD;
    }
};