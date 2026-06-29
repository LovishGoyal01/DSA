
class Solution {
public:
    int climb(int n, int i, vector<int>& dp) {
        if (i == n) return 1;
        if (i > n) return 0;

        if (dp[i] != -1) return dp[i];

        return dp[i] = climb(n, i + 1, dp) + climb(n, i + 2, dp);
    }

    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return climb(n, 0, dp);
    }
};



