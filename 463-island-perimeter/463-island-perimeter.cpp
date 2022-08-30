class Solution {
public:
    
    int row, col;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    bool isValid(int x, int y, vector<vector<int>>& grid){
        if(x < 0 || y < 0 || x >= row || y >= col || grid[x][y] == 0) return false; 
        return true;
    }
    
    void dfs(int x, int y, int &count, vector<vector<int>>& grid){
        grid[x][y] = 2;
        for(int i=0;i<4;i++){
            if(isValid(x + dx[i], y + dy[i], grid) && grid[x + dx[i]][y + dy[i]] != 2) dfs(x + dx[i], y + dy[i], count, grid);
            else if(isValid(x + dx[i], y + dy[i], grid) == false) count++;
        }
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        row = grid.size(), col = grid[0].size();
        int count = 0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j] == 1) dfs(i, j, count, grid);
            }
        }
        return count;
    }
};