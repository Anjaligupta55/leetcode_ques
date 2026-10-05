class Solution {
public:
    int solve(int i, int walls, vector<int>& cost, vector<int>& time,
              vector<vector<int>>& dp) {

        int n = cost.size();

        if (walls >= n)
            return 0;

        if (i == n)
            return 1e9;

        if (dp[i][walls] != -1)
            return dp[i][walls];

        // Take paid painter
        int take = cost[i] +
                   solve(i + 1, walls + 1 + time[i],
                         cost, time, dp);

        // Don't take paid painter
        int notTake =
            solve(i + 1, walls, cost, time, dp);

        return dp[i][walls] = min(take, notTake);
    }

    int paintWalls(vector<int>& cost, vector<int>& time) {

        int n = cost.size();

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return solve(0, 0, cost, time, dp);
    }
};