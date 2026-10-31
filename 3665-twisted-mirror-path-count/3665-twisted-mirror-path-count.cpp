class Solution {
vector<vector<vector<int>>> dp;
int MOD = 1e9 + 7, n, m;
private:
    int rec(int x, int y, vector<vector<int>>& grid, int dir) {
        if(x == n - 1 && y == m - 1) return 1;
        if(x >= n || y >= m) return 0;
        if(dp[x][y][dir] != -1) return dp[x][y][dir];
        long long ways = 0;
        if(grid[x][y] == 1) {
            if(dir) ways = rec(x + 1, y, grid, 0);
            else ways = rec(x, y + 1, grid, 1);
        }
        else ways += rec(x + 1, y, grid, 0) + rec(x, y + 1, grid, 1);
        return dp[x][y][dir] = ways % MOD;
    }  
public:
    int uniquePaths(vector<vector<int>>& grid) {
        n = grid.size(); m = grid[0].size();
        dp.resize(n, vector<vector<int>>(m, vector<int>(2, -1)));
        return rec(0, 0, grid, 0);
    }
};