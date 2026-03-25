class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left=0;
        int right=nums.size()-1;
        int ans=nums.size();
        int mid=(left+right)/2;
        while(left<=right){
            if(nums[mid]>=target) {
                ans=mid;
                right=mid-1;
            }
            else left=mid+1;
            mid=(left+right)/2;
        }
        return ans;
    }
};