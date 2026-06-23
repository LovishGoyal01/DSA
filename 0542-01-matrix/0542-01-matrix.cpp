class Solution {
public:
    void bfs(vector<vector<int>>& mat, queue<pair<pair<int,int>,int>>& q,vector<vector<int>>& ans){
        int n=mat.size();
        int m=mat[0].size();
        int delr[4] = {-1,0,1,0};
        int delc[4] = {0,-1,0,1}; 
        while(!q.empty()){
            int i = q.front().first.first;
            int j = q.front().first.second;
            int d = q.front().second;
            q.pop();
            for(int z=0;z<4;z++){
                int nr = i + delr[z];
                int nc = j + delc[z];
                if(nr>=0 && nc>=0 && nr<n && nc<m && ans[nr][nc]==-1){
                    ans[nr][nc] = d+1;
                    q.push({{nr,nc},d+1});
                }
            }   
        } 
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>ans(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                   q.push({{i,j},0});
                   ans[i][j]=0;
                }
            }
        }
         bfs(mat,q,ans);
         return ans;
    }
};