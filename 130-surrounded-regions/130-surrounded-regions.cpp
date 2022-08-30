class Solution {
public:
    
    int row, col;
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    
    bool isValid(int x, int y, vector<vector<char>>& grid){
        if(x < 0 || y < 0 || x >= row || y >= col) return false;
        if(grid[x][y] == 'X' || grid[x][y] == '#') return false;
        return true;
    }
    
    void dfs(int x, int y, vector<vector<char>>& grid){
        grid[x][y] = '#';
        for(int i=0;i<4;i++){
            if(isValid(x + dx[i], y + dy[i], grid)) dfs(x + dx[i], y + dy[i], grid);
        }
    }
    
    void solve(vector<vector<char>>& board) {
        row = board.size(), col = board[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j] == 'O'){
                    if(i == 0 || j == 0 || i == row - 1 || j == col - 1) dfs(i, j, board);
                }
            }
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
};