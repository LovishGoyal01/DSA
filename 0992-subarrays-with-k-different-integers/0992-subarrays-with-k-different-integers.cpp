class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
       return ans(nums,k)-ans(nums,k-1);   
    }

    int ans(vector<int>& arr, int k) {
        int l=0,r=0,cnt=0;
        map<int,int>mpp;
        int n=arr.size();
        while(r<n){
            mpp[arr[r]]++;
            while(mpp.size()>k){
                mpp[arr[l]]--;
                if(mpp[arr[l]]==0) mpp.erase(arr[l]);
                l++;
            }
            cnt+=r-l+1;
            r++;
        }
        return cnt;
    }
};