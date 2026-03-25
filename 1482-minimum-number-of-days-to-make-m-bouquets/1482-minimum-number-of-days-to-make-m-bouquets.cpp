class Solution {
public:
    
    int possible(vector<int>& bloomDay,int mid,int k,int m){
        int cnt=0,noB=0;

      for(int i=0;i<bloomDay.size();i++){
        if(bloomDay[i]>mid){
            noB+=cnt/k;
            cnt=-1;
        }
        cnt++;
      }
      noB+=(cnt/k);
      if(noB>=m) return 1;
       return 0;
    }
    vector<int>mini(vector<int>bloomDay){
        int maxv=INT_MIN;
        int minv=INT_MAX;
        for(int i=0;i<bloomDay.size();i++){
            maxv=max(maxv,bloomDay[i]);
            minv=min(minv,bloomDay[i]);
        }
        return {minv,maxv};
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        auto it=mini(bloomDay);
        int low = it[0];
        int high = it[1];
        int ans=-1;
        int n=bloomDay.size();
        int mid=0;
        while(low<=high){
            mid=(low+high)/2;
            if(possible(bloomDay,mid,k,m)){
                ans=mid;
                high=mid-1;
            }else low=mid+1;
        }
        return ans;
    }
};