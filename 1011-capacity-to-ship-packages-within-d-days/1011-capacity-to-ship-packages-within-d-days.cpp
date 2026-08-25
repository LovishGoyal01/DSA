class Solution {
public:

    int fxn(vector<int>& weights, int mid, int days){
        int sum=0,cnt=0;
        for(int i=0;i<weights.size();i++){
            sum+=weights[i];
            if(sum>mid){
                cnt++;
                sum=weights[i];
            }
        }
        if(cnt+1<=days) return 1;
        return 0;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);
        int mid,ans=-1;
        while(low<=high){
            mid =(low+high)/2;
            if(fxn(weights,mid,days)==1){
                high=mid-1;
                ans=mid;
            }else low=mid+1;
        }
        return ans;
    }
};