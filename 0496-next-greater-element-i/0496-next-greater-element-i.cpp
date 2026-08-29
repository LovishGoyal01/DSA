class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
     stack<int>st;
     int n=nums2.size();
     vector<int> ans(nums1.size(),-1);
     int i=n-1,val;
     while(i>=0){
        while(!st.empty() && st.top()<=nums2[i]) st.pop();
        if(st.empty()) val=-1;
        else val=st.top();
        st.push(nums2[i]);
        for(int j=0;j<nums1.size();j++){
            if(nums2[i]==nums1[j]) ans[j]=val;
        }
        i--;
     } 
     return ans;  
    }
};