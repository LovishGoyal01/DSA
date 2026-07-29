class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int,int>>q;
        q.push({sr,sc});
        int m=image.size();
        int n= image[0].size();
        
        int dr[4] = {-1,0,1,0};
        int dc[4] = {0,-1,0,1};
        
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        visited[sr][sc]=1;
        int prevColor=image[sr][sc];
        image[sr][sc] = color;
        
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr = r+dr[i];
                int nc = c+dc[i];
                if(nr>=0 && nr<m && nc>=0 && nc<n && image[nr][nc]==prevColor && !visited[nr][nc] ){
                    visited[nr][nc]=1;
                    q.push({nr,nc});
                    image[nr][nc]=color;
                }
            }
        }
        return image;
    }
};