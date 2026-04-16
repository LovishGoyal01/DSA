class Solution {
public:
    void rec(vector<int>& candidates, int index, int target,vector<vector<int>>& ans,vector<int> arr){
        if(index==candidates.size()){
            if(target==0){
                ans.push_back(arr);
            }
            return;
        }
        if(candidates[index]<=target){
            arr.push_back(candidates[index]);
            rec(candidates,index,target-candidates[index],ans,arr);
            arr.pop_back(); 
        }
        rec(candidates,index+1,target,ans,arr);
    }
 
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int> arr;
        rec(candidates,0,target,ans,arr);
        return ans;
    }
};