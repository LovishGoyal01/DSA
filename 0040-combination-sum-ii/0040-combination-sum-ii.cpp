class Solution {
public:
     void rec(vector<int>& candidates, int index, int target,vector<vector<int>>& ans,vector<int> arr){
        if(target==0){
            ans.push_back(arr);
            return;
        }
        for(int i = index ; i<candidates.size();i++){
            if(i>index && candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>target) break;
             arr.push_back(candidates[i]);
             rec(candidates,i+1,target-candidates[i],ans,arr);
             arr.pop_back();
        }

    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int> arr;
        sort(candidates.begin(), candidates.end());
        rec(candidates,0,target,ans,arr);
        return ans;
    }
};