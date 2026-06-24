class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int,pair<int,int>>> q;
        int n= grid.size();
        int m=grid[0].size();
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        int dr[8]= {1,1,1,0,0,-1,-1,-1};
        int dc[8]= {1,0,-1,1,-1,1,0,-1};
        if(grid[0][0]!=0) return -1;
        q.push({0,{0,0}});
        dist[0][0]=0;
        while(!q.empty()){
            int wt = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;
            q.pop();
            if(r==n-1 && c==m-1) return wt+1;
            else {
                for(int i=0;i<8;i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==0 && dist[nr][nc]> 1+wt){
                    q.push({wt+1,{nr,nc}});
                    dist[nr][nc]=1+wt;
                }
              }
            }       
        }
        return -1;
    }
};