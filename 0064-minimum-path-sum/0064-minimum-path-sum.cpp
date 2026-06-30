class Solution {
public:
    int path(vector<vector<int>>& grid,int i,int j,vector<vector<int>>& dp){
        if(i==0 && j==0) return grid[i][j];
        if(i<0 || j<0) return 1e9;
        if(dp[i][j]!=-1) return dp[i][j];
        int up =path(grid,i-1,j,dp);
        int left = path(grid,i,j-1,dp);
        return dp[i][j]= min(up,left) + grid[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0) dp[0][0]=grid[0][0];
                else{
                    int up=1e9,left=1e9;
                    if(i>0) up = grid[i][j]+dp[i-1][j];
                    if(j>0) left = grid[i][j]+dp[i][j-1];
                    dp[i][j] = min(up,left);
                }
            }
        }
        return dp[n-1][m-1];
    }
};