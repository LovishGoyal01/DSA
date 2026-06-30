class Solution {
public:
    int path(int i,int j,vector<vector<int>>&dp,vector<vector<int>>& grid){
        if(i<0 || j<0 || grid[i][j]==1) return 0;
        if(i==0 && j==0) return 1;
        
        if(dp[i][j]!=-1) return dp[i][j];
        int left = path(i,j-1,dp,grid);
        int top = path(i-1,j,dp,grid);
        return dp[i][j] = top+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return path(m-1,n-1,dp,obstacleGrid);
    }
};