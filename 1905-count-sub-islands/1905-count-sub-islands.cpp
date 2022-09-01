class Solution {
public:
    
    int row, col;
    int vis[501][501];
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    bool isValid(int x, int y, vector<vector<int>>& grid1, vector<vector<int>>& grid2){
        if(x < 0 || y < 0 || x >= row || y >= col || grid2[x][y] == 0 || vis[x][y] == 1) return false;
        return true;
    }
    
    void dfs(int x, int y, bool& flag, vector<vector<int>>& grid1, vector<vector<int>>& grid2){
        vis[x][y] = 1;
        if(grid1[x][y] == 0) flag = true;
        for(int i=0;i<4;i++){
            if(isValid(x + dx[i], y + dy[i], grid1, grid2)) dfs(x + dx[i], y + dy[i], flag, grid1, grid2);
        }
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        row = grid1.size(), col = grid1[0].size();
        memset(vis, 0, sizeof(vis));
        int count = 0;
        for(int i=0;i<grid2.size();i++){
            for(int j=0;j<grid2[0].size();j++){
                bool flag = false;
                if(grid2[i][j] == 1 && vis[i][j] == 0){
                    dfs(i, j, flag, grid1, grid2);
                    if(!flag) count++;
                }
            }
        }
        return count;
    }
};