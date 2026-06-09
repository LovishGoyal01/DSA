class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto it:mpp){
          pq.push({it.second,it.first});
        }
        vector<int>ans;
        for(int i=0;i<k;i++){
          pair<int,int>p=pq.top();
          pq.pop();
          ans.push_back(p.second);
        }
        return ans;
    }
};