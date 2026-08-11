class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totsum = accumulate(nums.begin(),nums.end(),0);
        if(totsum%2==1) return false;
        vector<vector<int>>dp(nums.size()+1,vector<int>(totsum/2+1,-1));
        return check(nums.size()-1,0,nums,totsum/2,dp);
    }
    bool check(int i, int s1,vector<int>& nums,int tosum,vector<vector<int>>& dp){
        if(i==0){
            if(s1+nums[i]==tosum || s1==tosum) return true;
            return false;
        }
        if(dp[i][s1]!=-1) return dp[i][s1];
        int take = false;
        if(s1+nums[i]<=tosum) take =  check(i-1,s1+nums[i],nums,tosum,dp);
         return dp[i][s1] = take || check(i-1,s1,nums,tosum,dp);
    }
};