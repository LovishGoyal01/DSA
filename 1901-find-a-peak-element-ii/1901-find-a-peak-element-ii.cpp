class Solution {
public:
    int findmax(vector<vector<int>>& matrix,int mid){
        int maxi=-1,index=-1;
        for(int i=0;i<matrix.size();i++){
            if(maxi<matrix[i][mid]){
                index=i;
                maxi=matrix[i][mid];
            }
        }
        return index;
    }

    vector<int> findPeakGrid(vector<vector<int>>& matrix) {
      int m=matrix[0].size();  
      int low=0;
      int high=m-1,mid,left,right,maxelR;  
      while(low<=high){
        mid=(low+high)/2;
        maxelR=findmax(matrix,mid);
        left= mid-1>=0? matrix[maxelR][mid-1] : -1;
        right= mid+1<m? matrix[maxelR][mid+1] : -1;
        if(matrix[maxelR][mid]>left && matrix[maxelR][mid]>right) return{maxelR,mid};
        else if(matrix[maxelR][mid]>left) low=mid+1;
        else high=mid-1;
      }
      return {-1,-1};
    }
};