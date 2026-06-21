class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        if(coins<=0) return 0;
        sort(costs.begin(),costs.end());
        int i=0;
        for(i=0;i<costs.size();i++){
            if(coins-costs[i]<0) break;
            coins = coins-costs[i];
        }
        return i;
    }
};