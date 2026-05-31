class Solution {
public:
    int calc(vector<int>& arr,int mid, int h){
        long long total=0;
        for(int i=0;i<arr.size();i++){
            total+=ceil((double)arr[i]/mid);
        }
        if(total<=h) return 1;
        return 0;
    }

    int minEatingSpeed(vector<int>& arr, int h) {
        int n=arr.size();
        int low=1;
        int high=*max_element(arr.begin(),arr.end());
        int mid,ans;
        while(low<=high){
            mid=(low+high)/2;
            if(calc(arr,mid,h)==1){
                high=mid-1;
                ans=mid;
            }else low=mid+1;
        }
        return ans;
    }
};