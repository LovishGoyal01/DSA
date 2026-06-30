class Solution {
public:
    int path(vector<vector<int>>& triangle,int i,int j,vector<vector<int>>& dp){
        if(i==triangle.size()-1) return dp[i][j] =  triangle[i][j];
        if(dp[i][j]!=1e9) return dp[i][j];
        int down1 = path(triangle,i+1,j,dp);
        int down2 = path(triangle,i+1,j+1,dp);
    
        return dp[i][j] =  min(down1,down2) + triangle[i][j];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[n-1].size();
        vector<vector<int>>dp(n,vector<int>(m,1e9));
        return path(triangle,0,0,dp);
    }
};