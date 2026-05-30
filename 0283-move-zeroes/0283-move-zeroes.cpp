class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        int i=0,j;
        for(int j=0;j<arr.size();j++){
            if(arr[j]!=0){
              swap(arr[i],arr[j]);
              i++;
            }
        }
    }
};