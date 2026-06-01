class Solution {
public:
    
    int possible(vector<int>& arr, int mid,int k){
        int painter=1,total=0;
        for(int i=0;i<arr.size();i++){
            if(total+arr[i]<=mid) total+=arr[i];
            else{
                painter++;
                total=arr[i];
            }
        }
        if(painter<=k) return 1;
        return 0;
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        int mid=0,ans=high;
        while(low<=high){
          mid=(low+high)/2;
          if(possible(nums,mid,k)){
            ans=mid;
            high=mid-1;
          }else low=mid+1;
        }
        return ans;
    }
};