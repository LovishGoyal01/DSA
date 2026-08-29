class Solution {
public:
    void nge(vector<int>& height,vector<int>& ng){
       int n = height.size();
       int mx = height[n-1];
       for(int i=n-1;i>=0;i--){
         mx = max(height[i],mx);
         ng[i] = mx;
       }
    }

    void pge(vector<int>& height,vector<int>& pg){
       int n = height.size();
       int mx = height[0];
       for(int i=0;i<n;i++){
        mx = max(height[i],mx);
         pg[i] = mx;
       }
    }

    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>ng(n,0);
        vector<int>pg(n,0);
        nge(height,ng);
        pge(height,pg);
        int sum = 0;
        for(int i=0;i<n;i++){
            sum+= min(ng[i],pg[i]) - height[i];
        }
        return sum;
    }
};