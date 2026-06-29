class Solution {
public:
    int robber(vector<int>& nums) {
        int prev1=nums[0],prev2=0;
        for(int i=1;i<nums.size();i++){
            int take = nums[i]+prev2;
            int nottake = 0 + prev1;
            int maxi=max(take,nottake);
            prev2=prev1;
            prev1=maxi;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return nums[0];

        vector<int> temp1, temp2;

        for (int i = 0; i < n; i++) {
            if (i != 0) temp1.push_back(nums[i]);
            if (i != n - 1) temp2.push_back(nums[i]);
        }

        return max(robber(temp1), robber(temp2));
    }

};