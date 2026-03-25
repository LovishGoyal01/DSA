class Solution {
public:

    int possible(vector<int>& nums, int threshold,int mid){
        int cnt=0;
        for(int i=0;i<nums.size();i++){
          cnt+=ceil((double)nums[i] / mid);
        }
        if(cnt<=threshold) return 1;
        return 0;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
         int n= nums.size();
         int low= 1;
         int high=*max_element(nums.begin(),nums.end());
         if(n==threshold) return high;
         int ans= high;
         int mid=0;
         while(low<=high){
            mid=(low+high)/2;
            if(possible(nums,threshold,mid)){
             ans=mid;   
             high=mid-1;
            }else low=mid+1;
         }
         return ans;
    }
};