class Solution {
public:
    int calc(vector<int>& arr,int mid, int days){
        int total=0,count=1;
        for(int i=0;i<arr.size();i++){
            if(total+arr[i]>mid){
                count++;
                total=arr[i];
            }else total+=arr[i];
        }
        if(count<=days) return 1;
        return 0;
    }

    int shipWithinDays(vector<int>& arr, int days) {
        int n=arr.size();
        int low = *max_element(arr.begin(), arr.end());
        int high=accumulate(arr.begin(),arr.end(),0);
        int mid,ans=-1;
        while(low<=high){
            mid=(low+high)/2;
            if(calc(arr,mid,days)==1){
                high=mid-1;
                ans=mid;
            }else low=mid+1;
        }
        return ans;
    }
};