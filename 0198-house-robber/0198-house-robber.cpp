class Solution {
public:
    int robber(int index , vector<int>& nums , vector<int>& dp) {
        if(index==0 || index==1) return dp[index] = nums[index];
        if(dp[index]!=-1) return dp[index];
        int jump=0,maxA=INT_MIN;
        for(int j=index-2;j>=0;j--){
            if(j>=0) jump = robber(j,nums,dp) + nums[index];
            maxA=max(maxA,jump);
        }
        return dp[index]=maxA;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n<=1) return nums[0];
        if(n<=2) return max(nums[0],nums[1]);
        vector<int>dp(n,-1);
        return max(robber(n-1,nums,dp),robber(n-2,nums,dp));
    }
};