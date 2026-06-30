class Solution {
public:
    int path(int i,int j,vector<vector<int>>&dp){
        if(i==0 && j==0) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int left = j-1>=0? path(i,j-1,dp) : 0;
        int top =  i-1>=0 ? path(i-1,j,dp) : 0;
        return dp[i][j] = top+left;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return path(m-1,n-1,dp);
    }
};