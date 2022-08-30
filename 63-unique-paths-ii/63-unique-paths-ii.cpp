class Solution {
public:
    
    int row, col;
    int dp[101][101];
    
    int solve(int i, int j, vector<vector<int>>& grid){
        if(i >= row || j >= col || grid[i][j] == 1) return 0;
        if(i == row - 1 && j == col - 1) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = solve(i + 1, j, grid) + solve(i, j + 1, grid);
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        row = grid.size(), col = grid[0].size();
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, grid);
    }
};