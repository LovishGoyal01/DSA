class Solution {
public:
    int calc(vector<int>& arr,int mid, int t){
        int total=0;
        for(int i=0;i<arr.size();i++){
            total+=ceil((double)arr[i]/mid);
        }
        if(total<=t) return 1;
        return 0;
    }

    int smallestDivisor(vector<int>& arr, int t) {
      int n=arr.size();  
      int low=1;
      int high=*max_element(arr.begin(),arr.end());
      int mid,ans=-1;
      while(low<=high){
        mid=(low+high)/2;
        if(calc(arr,mid,t)==1){
            high=mid-1;
            ans=mid;
        }else low=mid+1;
      }
      return ans;
    }
};