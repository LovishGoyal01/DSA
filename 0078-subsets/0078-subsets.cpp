class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        int n = nums.size();
        for(int k=0;k<(1<<n);k++){
             vector<int> arr;
             for(int i=0;i<n;i++){
                if(k & (1<<i)) arr.push_back(nums[i]);
             }
             ans.push_back(arr);
        }
        return ans;
    }
};