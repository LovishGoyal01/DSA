class Solution {
public:
    vector<int> rightMax(vector<int>& arr){
        int n=arr.size();
        vector<int> ans(n,-1);
        ans[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--){
            if(arr[i]>=ans[i+1]) ans[i]=arr[i];
            else ans[i]=ans[i+1];
        }
        return ans;
    }
    int trap(vector<int>& heights) {
        int n=heights.size();
        int prevmax=-1,maxi,total=0;
        vector<int>ans=rightMax(heights);
        for(int i=0;i<n-1;i++){
            if(prevmax<heights[i]) prevmax=heights[i];
           maxi=min(prevmax,ans[i]);
           if(maxi>heights[i]) total += maxi - heights[i];
        }
        return total;
    }
};