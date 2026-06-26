class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        int maxi = grid[0][0];
        pq.push({grid[0][0],{0,0}});
        int n =grid.size();
        vector<vector<int>>vis(n,vector<int>(n,0));
        vis[0][0]=1;
        int dr[4] = {-1,0,1,0};
        int dc[4] = {0,-1,0,1};
        while(!pq.empty()){
            auto it = pq.top();   pq.pop();
            maxi = max(maxi,it.first);
            int row = it.second.first;
            int col = it.second.second;
            if(row==n-1 && col==n-1) return maxi;
            for(int i=0;i<4;i++){
                int nr = row + dr[i];
                int nc = col + dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<n && !vis[nr][nc]){
                    vis[nr][nc]=1;
                    pq.push({grid[nr][nc],{nr,nc}});
                }
            } 
        } 
        return -1;
    }
};