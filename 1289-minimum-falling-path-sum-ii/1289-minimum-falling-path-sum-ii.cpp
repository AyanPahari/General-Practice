class Solution {
public:
    
    int n;
    int dp[201][201];
    int solve(int row, int col, vector<vector<int>>& grid){
        if(row >= n || col < 0 || col >= n) return INT_MAX;
        if(row == n - 1) return grid[row][col];
        if(dp[row][col] != -1) return dp[row][col];
        int ans = INT_MAX;
        for(int i=0;i<n;i++) if(i != col) ans = min(ans, solve(row + 1, i, grid));
        return dp[row][col] = ans + grid[row][col];
    }
    
    int minFallingPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        int res = INT_MAX;
        memset(dp, -1, sizeof(dp));
        for(int i=0;i<n;i++) res = min(res, solve(0, i, grid));
        return res;
    }
};