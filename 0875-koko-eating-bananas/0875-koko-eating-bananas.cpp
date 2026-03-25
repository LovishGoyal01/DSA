class Solution {
public:
   
    int findmax(vector<int>piles){
        int maxi=0;
        for(int i=0;i<piles.size();i++){
            maxi=max(maxi,piles[i]);
        }
        return maxi;
    }

    int calc(vector<int>& piles, int h, int mid){
      long long count = 0;

      for(int i = 0; i < piles.size(); i++){
        count += ceil(double(piles[i])/double(mid));
      }

      if(count > h) return -1;   
      return 1;                  
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int low=1;
        int high=findmax(piles);
        int mid=0,ans=-1;
        while(low<=high){
            mid=(low+high)/2;
            int v = calc(piles,h,mid);
            if(v==1){
                high=mid-1;
                ans=mid;
            }
            else low=mid+1;
        }
        return ans;
    }
};