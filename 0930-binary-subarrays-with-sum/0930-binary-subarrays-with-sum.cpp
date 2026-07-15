class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return sum(nums,goal)-sum(nums,goal-1);
    }

    int sum(vector<int>& nums, int k){
        int l=0,r=0,sum=0,count=0;
        int n = nums.size();
         for(int r=0;r<n;r++){
            sum+=nums[r];
            while(sum>k && l<=r){
                sum-=nums[l];
                l++;
            }
            count += (r-l+1);
         }
         return count;
    }
};