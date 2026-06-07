class Solution {
public:
    int longestOnes(vector<int>& arr, int k) {
        int nz=0;
        int l=0,maxi=0;
        int n=arr.size();
       
        for(int i=0;i<n;i++){
            if(arr[i]==0){
                nz++;
            }
            if(nz>k){
                if(arr[l]==0) nz--;
                l++;
            }
             maxi=max(maxi,i-l+1);
        }
        return maxi;
    }
};