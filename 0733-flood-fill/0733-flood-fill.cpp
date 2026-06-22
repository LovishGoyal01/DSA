class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m =image[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        q.push({sr,sc});
        visited[sr][sc]=1;
        while(!q.empty()){
            auto it = q.front();   q.pop();
            int dr[4] = {-1,0,1,0};
            int dc[4] = {0,-1,0,1};
            for(int i=0;i<4;i++){
                int nr = it.first + dr[i];
                int nc = it.second + dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && !visited[nr][nc] && image[nr][nc]==image[sr][sc]){
                   visited[nr][nc]=1;
                   q.push({nr,nc});
                   image[nr][nc]=color; 
                }
            }
        }
          image[sr][sc]=color;
        return image;
    }
};