class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
       
       int m = grid.size();
       int n = grid[0].size();
       vector<vector<int>> visited(m, vector<int>(n, 0));
       queue<pair<pair<int,int>,int>>q;
       int cnt = 0;
       for(int i=0;i<m;i++){
         for(int j=0;j<n;j++){
            visited[i][j]=grid[i][j];
            if(grid[i][j]==2) q.push({{i,j},0});
            else if(grid[i][j]==1) cnt++;
         }
       }
       int count=0;
       int time=0;
       int cols[] = {-1,0,1,0};
       int rows[] = {0,-1,0,1};

       while(!q.empty()){
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        time = max(t,time);
        q.pop();
        for(int i=0;i<4;i++){
            int rn = r+rows[i];
            int cn = c+cols[i];
            if(rn >= 0 && rn < m && cn >= 0 && cn < n && visited[rn][cn] == 1){
                q.push({{rn,cn},t+1});
                visited[rn][cn]=2;
                count++;
            }
        }
       } 
      if(cnt!=count) return -1;
      return time;
    }
};