class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=prices[0],maxi=0;
        for(int i=0;i<prices.size();i++){
            maxi = max(maxi,prices[i]-mini);
            mini= min(mini,prices[i]);
        }
        return maxi;
    }
};