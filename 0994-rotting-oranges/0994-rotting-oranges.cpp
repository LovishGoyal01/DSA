class Solution {
public:
      int bfs(vector<vector<int>>& grid,queue<pair<int,pair<int,int>>>& q,vector<vector<int>>&visited,int cntFresh) {
        int n = grid.size();
        int m =grid[0].size();
        int dr[4] = {-1,0,1,0};
        int dc[4] = {0,-1,0,1};
        int ans=0,cnt=0;
        while(!q.empty()){
            auto it = q.front();   q.pop();
            int r=it.first;
            int c=it.second.first;
            int t=it.second.second;
              for(int i=0;i<4;i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && !visited[nr][nc] && grid[nr][nc]==1){
                   visited[nr][nc]=1;
                   q.push({nr,{nc,t+1}});
                   grid[nr][nc]=2;
                   cnt++; 
                }
              }
            ans=t;
        }
        return cnt==cntFresh?ans:-1;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0,cntFresh=0;
        vector<vector<int>>visited(n,vector<int>(m,0));
        queue<pair<int,pair<int,int>>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                   q.push({i,{j,0}});
                   visited[i][j]=1;
                }
                if(grid[i][j]==1) cntFresh+=1;
            }
        }
        cnt  = bfs(grid,q,visited,cntFresh);
        return cnt;
    }
};