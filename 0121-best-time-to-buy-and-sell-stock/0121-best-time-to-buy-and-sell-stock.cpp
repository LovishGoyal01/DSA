class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int mini=arr[0];
        int maxP=0,cost=0;
        for(int i=1;i<arr.size();i++){
            if(arr[i]>mini){
             cost = arr[i]-mini;
             maxP = max(cost,maxP);
            }else mini=arr[i];
        }
        return maxP;
    }
};