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
        return path(grid,n-1,m-1,dp);
    }
};