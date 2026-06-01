class Solution {
public:
    bool answer(vector<int> row, int target){
        int low=0;
        int high=row.size()-1;
        int mid;
        while(low<=high){
            mid=(low+high)/2;
            if(row[mid]==target) return true;
            else if(row[mid]>target) high=mid-1;
            else low=mid+1;
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();

        for(int i=0;i<n;i++){
            if(matrix[i][0]<=target && target<=matrix[i][m-1]){
              return(answer(matrix[i],target));
            }
        }
         return false;
    }
   
};