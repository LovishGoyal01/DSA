class Solution {
public:
    vector<int> total(vector<int>& weights){
        int sum=0,maxi=0;
        for(int i=0;i<weights.size();i++){
            sum+=weights[i];
            maxi=max(maxi,weights[i]);
        }
        return {maxi,sum};
    }

    int possible(vector<int>& weights, int days,int mid){
        int cnt=0,sum=0;
        for(int i=0;i<weights.size();i++){
          sum=sum+weights[i];
          if(ceil((double)sum / mid)==2){
            cnt++;
            sum=weights[i];
          }
        }
        if(cnt+1<=days) return 1;
        return 0;
    }

    int shipWithinDays(vector<int>& weights, int days) {
       auto it = total(weights);
       int low = it[0];
       int high = it[1];
       int mid=0,ans=high;
       while(low<=high){
         mid = (low+high)/2;
         if(possible(weights,days,mid)){
            ans=mid;   
             high=mid-1;
        }else low=mid+1;
       }
     return ans; 
    }
};