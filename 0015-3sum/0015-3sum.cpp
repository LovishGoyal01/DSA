class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int i,j,k,sum;

        vector<vector<int>> ans;

        for(i=0;i<n-1;i++){
            if(i>0 && arr[i]==arr[i-1]) continue;
            j=i+1;
            k=n-1;
            while(j<k){
                sum=arr[i]+arr[j]+arr[k];
                if(sum>0) k--;
                else if(sum<0) j++;
                else{
                  ans.push_back({arr[i],arr[j],arr[k]});
                  j++;
                  k--;
                  while(j<k && arr[j]==arr[j-1]) j++;
                  while(j<k && arr[k]==arr[k+1]) k--;
                }
            }
        }
        return ans;
    }
};