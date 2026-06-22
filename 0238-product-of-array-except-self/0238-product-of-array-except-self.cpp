class Solution {
public:
    vector<int> productExceptSelf(vector<int>& arr) {
    int prefix=1,suffix =1;
     int n=arr.size();
     vector<int>ans(n,1);
      for(int i=0;i<n;i++){
        ans[i]*=prefix;
        prefix*=arr[i];
        ans[n-1-i]*=suffix;
        suffix*=arr[n-1-i];
      }
      return ans;
    }   
    
};