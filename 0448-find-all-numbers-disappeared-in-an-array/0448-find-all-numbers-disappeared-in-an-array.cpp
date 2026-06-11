class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        set<int>st;
        vector<int>ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        int i=1;
        while(i<=n){
           if(!st.count(i)) ans.push_back(i);
           i++;
        }
        return ans;
    }
};