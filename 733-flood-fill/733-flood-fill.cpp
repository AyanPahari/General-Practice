class Solution {
public:
    
    int vis[51][51];
    int row, col, own_color;
    int dx[4]={-1, 0, 1, 0};
    int dy[4]={0, 1, 0, -1};
    
    bool isValid(int x, int y, vector<vector<int>>& grid, int color){
        if(x < 0 || y < 0 || x >= row || y >= col) return false;
        if(vis[x][y] == 1 || grid[x][y] == color || grid[x][y] != own_color) return false;
        return true;
    }
    
    void dfs(int x, int y, int color, vector<vector<int>>& grid){
        vis[x][y] = 1;
        grid[x][y] = color;
        
        for(int i=0;i<4;i++){
            if(isValid(x + dx[i], y + dy[i], grid, color)) dfs(x + dx[i], y + dy[i], color, grid);
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        row = image.size(), col = image[0].size();
        memset(vis, 0, sizeof(vis));
        own_color = image[sr][sc];
        dfs(sr, sc, color, image);
        return image;
    }
};