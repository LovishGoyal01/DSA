class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int nr = grid.size();
        int nc = grid[0].size();
        if(grid[0][0] == 1 || grid[nr-1][nc-1] == 1)
            return -1;
        if(nr==1 && nc==1)
        return 1;    

        queue<pair<int,pair<int,int>>>q;
        vector<vector<int>>dist(nr,vector<int>(nc,1e9));
        q.push({1,{0,0}});

        int dr[8] = {-1,-1,-1,0,0,1,1,1};
        int dc[8] = {-1,0,1,-1,1,-1,0,1};

        dist[0][0] = 1; 

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;

            for(int i=0;i<8;i++){
             int row = r + dr[i];
             int col = c + dc[i];
             if(row>=0 && col>=0 && row<nr && col<nc && grid[row][col]==0 && dist[row][col]>1+dis){
                if(row==nr-1 && col==nc-1) return 1+dis;
                dist[row][col]=1+dis;
                q.push({1+dis,{row,col}});
             }
            }
            
        }
       return -1;
    }
};