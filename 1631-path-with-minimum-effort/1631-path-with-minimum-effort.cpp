class Solution {
public:
    
    int row, col;
    int vis[101][101];
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    bool isValid(int x, int y, vector<vector<int>>& grid){
        if(x < 0 || y < 0 || x >= row || y >= col || vis[x][y] == 1) return false;
        return true;
    }
    
    bool dfs(int x, int y, vector<vector<int>>& grid, int limit){
        vis[x][y] = 1;
        if(x == row - 1 && y == col - 1) return true;
        for(int i=0;i<4;i++){
            int currX = x + dx[i];
            int currY = y + dy[i];
            if(isValid(currX, currY, grid)){
                if(abs(grid[x][y] - grid[currX][currY]) <= limit && dfs(currX, currY, grid, limit)) return true;
            }
        }
        return false;
    }
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        row = heights.size(), col = heights[0].size();
        int low = 0, high = INT_MIN, res = -1, mid;
        for(int i=0;i<heights.size();i++){
            for(int j=0;j<heights[0].size();j++){
                high = max(high, heights[i][j]);
            }
        }
        while(low <= high){
            mid = low + (high - low) / 2;
            memset(vis, 0, sizeof(vis));
            if(dfs(0, 0, heights, mid)){
                res = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return res;
    }
};