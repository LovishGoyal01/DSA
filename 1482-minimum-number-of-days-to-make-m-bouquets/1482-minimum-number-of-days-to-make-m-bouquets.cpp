class Solution {
public:
    int calc(vector<int>& arr,int mid, int m, int k){
        int ans=0,count=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]<=mid) count++;
            else{
                ans+=count/k;
                count=0;
            }
            
        }
        ans+=count/k;
        if(ans>=m) return 1;
        return 0;
    }

    int minDays(vector<int>& arr, int m, int k) {
        int low=1;
        int high=*max_element(arr.begin(),arr.end());
        int mid,ans=-1;
        while(low<=high){
            mid=(low+high)/2;
            if(calc(arr,mid,m,k)==1){
                ans=mid;
                high=mid-1;
            }else low=mid+1;
        }
        return ans;
    }
};