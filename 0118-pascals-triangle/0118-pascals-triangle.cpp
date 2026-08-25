class Solution {
public:
    vector<int> pascal(int row){
     int ans=1;
     vector<int>arr;
     arr.push_back(ans);
     for(int col=1;col<row;col++){
        ans*= (row-col);
        ans/= col;
        arr.push_back(ans); 
     }
     return arr;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=1;i<=numRows;i++){
            ans.push_back(pascal(i));
        }
        return ans;
    }
};