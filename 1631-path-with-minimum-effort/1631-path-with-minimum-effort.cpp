class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
         pq.push({0,{0,0}});
        int n = heights.size();
        int m = heights[0].size(); 
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX)); 
        dist[0][0] = 0;
        int dr[4] = {1,0,-1,0};
        int dc[4] = {0,1,0,-1};
        while(!pq.empty()){
            int e = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();
             for(int i=0;i<4;i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && dist[nr][nc]> abs(heights[r][c]-heights[nr][nc])
                  && dist[nr][nc]> e){
                    int ne = max(e,abs(heights[r][c]-heights[nr][nc]));
                    pq.push({ne,{nr,nc}});
                    dist[nr][nc]=ne;
                }
             }
        } 
        return dist[n-1][m-1];   
    }
};