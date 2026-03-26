class Solution {
public:
    
    int possible(vector<int>& nums, int k,int mid){
        int sum=0,cnt=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum> mid){
                cnt++;
                sum=nums[i];
            }
        }
        if(cnt+1<=k) return 1;
        return 0; 
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        int mid=0,ans=high;
        while(low<=high){
            mid=(low+high)/2;
            if(possible(nums,k,mid)){
                high=mid-1;
                ans=mid;
            }else low=mid+1;
        }
        return ans;
    }
};