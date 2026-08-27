class Solution {
public:
    void rec(vector<int>& candidates, int target,vector<int>& array,vector<vector<int>>& ans,int s){
        if(target==0){
            ans.push_back(array);
            return;
        }

        for(int i=s;i<candidates.size();i++){
            if(target - candidates[i]>=0){
             array.push_back(candidates[i]);
             rec(candidates,target- candidates[i],array,ans,i);
             array.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> array;
        rec(candidates,target,array,ans,0);
        return ans;
    }
};