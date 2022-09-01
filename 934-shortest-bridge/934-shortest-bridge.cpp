class Solution {
public:
    
    int vis[101][101];
    int dist[101][101];
    int n;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    bool isValid_dfs(int x, int y, vector<vector<int>>& grid){
        if(x < 0 || y < 0 || x >= n || y >= n || vis[x][y] == 1 || grid[x][y] == 0) return false;
        return true;
    }
    
     bool isValid_bfs(int x, int y, vector<vector<int>>& grid){
        if(x < 0 || y < 0 || x >= n || y >= n || vis[x][y] == 1) return false;
        return true;
    }
    
    void dfs(int x, int y, vector<vector<int>>& grid, queue<pair<int,int>>& q){
        vis[x][y] = 1;
        dist[x][y] = 0;
        q.push({x, y});
        for(int i=0;i<4;i++){
            if(isValid_dfs(x + dx[i], y + dy[i], grid)) dfs(x + dx[i], y + dy[i], grid, q);
        }
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();
        memset(vis, 0, sizeof(vis));
        memset(dist, -1, sizeof(dist));
        queue<pair<int,int>>q;
        bool flag = false;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1 && vis[i][j] == 0){
                    dfs(i, j, grid, q);
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }
        
        while(!q.empty()){
            int currX = q.front().first;
            int currY = q.front().second;
            q.pop();
            
            for(int i=0;i<4;i++){
                int newX = currX + dx[i];
                int newY = currY + dy[i];
                
                if(isValid_bfs(newX, newY, grid)){
                    vis[newX][newY] = 1;
                    dist[newX][newY] = dist[currX][currY] + 1;
                    q.push({newX, newY});
                    
                    if(grid[newX][newY] == 1) return dist[newX][newY] - 1;
                }
            }
        }
        return -1;
    }
};