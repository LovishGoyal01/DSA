class Solution {
public:
    vector<int> pse(vector<int>& arr){
        int n=arr.size();
        vector<int> p(n,-1);
        stack<int>st;
        for(int i=0;i<n;i++){
          while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
          p[i]=st.empty()?-1:st.top();
          st.push(i);
        }
        return p;
    }

    vector<int> nse(vector<int>& arr){
        int n=arr.size();
        vector<int> ns(n,n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
          while(!st.empty() && arr[st.top()]>arr[i]) st.pop();
          ns[i]=st.empty()?n:st.top();
          st.push(i);
        }
        return ns;
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int> ns=nse(heights);
        vector<int> ps=pse(heights);
        int n=heights.size();
        int ans=-1,maxi=-1;
        for(int i=0;i<n;i++){
         ans=heights[i]*(ns[i]-ps[i]-1);
         maxi=max(ans,maxi);
        }
        return maxi;
    }
};