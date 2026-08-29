class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        int n = nums2.size();
        vector<int>ans(n,-1);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums2[i]) st.pop();
            ans[i] = st.empty() ? -1 : st.top();
            st.push(nums2[i]);
        }
        vector<int>arr(nums1.size(),-1);
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<n;j++){
                if(nums1[i]==nums2[j]){
                    arr[i]=ans[j];
                    break;
                }
            }                         
        }
      return arr;
    }
};