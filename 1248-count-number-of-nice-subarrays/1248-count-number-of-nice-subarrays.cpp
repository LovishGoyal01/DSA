class Solution {
public:
    int Subarrays(vector<int>& arr, int k) {
        if(k<0) return 0;  
        int l=0,r=0,odd=0,cnt=0;
        int n=arr.size();
        while(r<n){
            if(arr[r]%2==1) odd++;
            while(odd>k){
                if(arr[l]%2==1) odd--;
                l++;
            }
            cnt+=r-l+1;
            r++;
        }
      return cnt;
    }

    int numberOfSubarrays(vector<int>& arr, int k) {
        return Subarrays(arr,k)-Subarrays(arr,k-1);
    }
};