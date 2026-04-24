class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n= nums2.size();
        map<int,int>mpp;
        stack<int>st;
        int mini=nums2[n-1];
        for(int i=n-1;i>=0;i--){
                while(!st.empty()){
                    if(st.top()>nums2[i]) break;
                    st.pop();
                }
                if(!st.empty()) mpp[nums2[i]]=st.top();
                else mpp[nums2[i]]=-1;
            st.push(nums2[i]);
        }
        vector<int>ans;
        for(int i=0;i<nums1.size();i++){
          ans.push_back(mpp[nums1[i]]);
        }
        return ans;
    }
};