class Solution {
public:
    int m, n;
    vector<vector<vector<int>>> dp;

    int dfs(vector<vector<int>>& grid, int i, int j, int xr) {
        if (i >= m || j >= n) {
            return INT_MAX;
        }

        xr ^= grid[i][j];

        if (i == m - 1 && j == n - 1) {
            return xr;
        }

        if (dp[i][j][xr] != -1) {
            return dp[i][j][xr];
        }

        int right = dfs(grid, i, j + 1, xr);
        int down = dfs(grid, i + 1, j, xr);

        return dp[i][j][xr] = min(right, down);
    }

    int minCost(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        dp.assign(m, vector<vector<int>>(
            n, vector<int>(1024, -1)
        ));

        return dfs(grid, 0, 0, 0);
    }
};