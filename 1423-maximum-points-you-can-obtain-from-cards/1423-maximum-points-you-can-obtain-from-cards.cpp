class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int n= arr.size();
        int lsum=0,rsum=0,rIndex=n-1,maxi=0;
        for(int i=0;i<k;i++){
            lsum+=arr[i];
        }
        maxi=max(lsum+rsum,maxi);
        for(int i=k-1;i>=0;i--){
            lsum-=arr[i];
            rsum+=arr[rIndex];
            rIndex--;
            maxi=max(maxi,lsum+rsum);
        }
        return maxi;
    }
};