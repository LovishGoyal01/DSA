class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int original = image[sr][sc];
        if(original == color) return image;
        
        int m = image.size();
        int n = image[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
              visited[i][j]=image[i][j];
            } 
        }
        
        queue<pair<int,int>>q;
        q.push({sr,sc});
        visited[sr][sc]=2;
        int rows[] = {-1,0,1,0};
        int cols[] = {0,-1,0,1};
        while(!q.empty()){
          auto it = q.front();  q.pop();
          int r = it.first;
          int c = it.second;
          for(int i=0;i<4;i++){
            int rn = r+rows[i];
            int cn = c+cols[i];
            if(rn>=0 && rn<m && cn>=0 && cn<n && visited[rn][cn]==original){
                q.push({rn,cn});
                visited[rn][cn]=color;
            }
          }
        }
      return visited;
    }
};