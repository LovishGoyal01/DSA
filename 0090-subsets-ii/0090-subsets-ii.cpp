class Solution {
public:
    void rec(vector<int>& nums,int ind,vector<int>arr,vector<vector<int>>& ans){
        ans.push_back(arr);

        for(int i = ind;i<nums.size();i++){
            if(i!=ind && nums[i]==nums[i-1]) continue;
            arr.push_back(nums[i]);
            rec(nums,i+1,arr,ans);
            arr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
         vector<vector<int>>ans;
        vector<int> arr;
        sort(nums.begin(), nums.end());
        rec(nums,0,arr,ans);
        return ans;
    }
};