class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
      int left=0,top=0;
      int m =  matrix.size();
      int n =  matrix[0].size();
      int right= n-1;
      int bottom=m-1; 
      vector<int>ans;
      while(left<=right && top<=bottom){
        for(int i= left;i<=right;i++){
            ans.push_back(matrix[top][i]);
        }
        top++;
        for(int j= top;j<=bottom;j++){
            ans.push_back(matrix[j][right]);
        }
        right--;

        if(top<=bottom){
        for(int i= right;i>=left;i--){
            ans.push_back(matrix[bottom][i]);
        }
        bottom--;
        }

        if(left<=right){
        for(int j= bottom;j>=top;j--){
            ans.push_back(matrix[j][left]);
        }
        left++;
        }

      }
      return ans;
    }
};