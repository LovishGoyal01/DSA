class Solution {
public:
    vector<int> generateRow(int row){
        vector<int>ans;
        int val=1;
        ans.push_back(1);
        for(int col=1;col<row;col++){
            val=val*(row-col);
            val=val/col;
            ans.push_back(val);
        } 
        return ans;
    }
    vector<vector<int>> generate(int n) {
        vector<vector<int>>ans; 
        for(int i=1;i<=n;i++){
            ans.push_back(generateRow(i));
        }
        return ans;
    }
};