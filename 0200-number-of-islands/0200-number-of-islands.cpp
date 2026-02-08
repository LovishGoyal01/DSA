class Solution {
public:

    void bfs(vector<vector<char>>& grid,vector<vector<int>>& visited,int row,int col){
        visited[row][col]=1;
        int m = grid.size();
        int n = grid[0].size();        

        queue<pair<int,int>>q;
        q.push({row,col});

        int delrow[] = {0,-1,0,1};
        int delcol[] = {-1,0,1,0};

        while(!q.empty()){
          int rn = q.front().first;  
          int cn = q.front().second;
          q.pop();
          for(int i=0;i<4;i++){
            int r = rn+delrow[i];
            int c = cn+delcol[i];
            if(r>=0 && r<m && c>=0 && c<n && !visited[r][c] && grid[r][c]=='1'){
                q.push({r,c});
                visited[r][c]=1;
            }
          }
        }  
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    cnt++;
                    bfs(grid,visited,i,j);
                } 
            }
        }
        return cnt;
    }
};