class Solution {
public:
    
    int row, col;
    int vis[301][301];
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    bool isValid(int x, int y, vector<vector<int>>& grid){
        if(x < 0 || y < 0 || x >= row || y >= col || grid[x][y] == 0 || vis[x][y] == 1) return false; 
        return true;
    }
    
    void dfs(int x, int y, vector<vector<int>>& land, int& endX, int& endY){
        vis[x][y] = 1;
        endX = max(endX, x);
        endY = max(endY, y);
        
        for(int i=0;i<4;i++){
            if(isValid(x + dx[i], y + dy[i], land)) dfs(x + dx[i], y + dy[i], land, endX, endY);
        }
    }
    
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>>res;
        row = land.size(), col = land[0].size();
        memset(vis, 0, sizeof(vis));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                int endX = 0, endY = 0;
                if(vis[i][j] == 0 && land[i][j] == 1){
                    dfs(i, j, land, endX, endY);
                    res.push_back({i, j, endX, endY});
                }
            }
        }
        return res;
    }
};