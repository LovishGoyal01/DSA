class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<pair<int,int>> arr;
        int n=nums.size();
        for(int i=0;i<n;i++){
            arr.push_back({nums[i],i});
        }
        sort(arr.begin(),arr.end());
        vector<int>ans(n,-1);
        int prev=0;
        ans[arr[0].second]=0;
        for(int i=1;i<n;i++){
           if(arr[i].first!=arr[i-1].first) prev=i;
           ans[arr[i].second]=prev;
        }
        return ans;
    }
};