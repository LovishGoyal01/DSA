class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
      sort(intervals.begin(),intervals.end());
      vector<vector<int>> ans;
      int pre=-1,post=-1;
      for(int i=0;i<intervals.size();i++){
        if(pre==-1){
            pre=intervals[i][0];
            post=intervals[i][1];
        }else if(intervals[i][0]<=post){
            post=max(post,intervals[i][1]);
        }else{
            ans.push_back({pre,post});
            pre=intervals[i][0];
            post=intervals[i][1];
        } 
      }
      ans.push_back({pre,post});
      return ans;   
    }
};