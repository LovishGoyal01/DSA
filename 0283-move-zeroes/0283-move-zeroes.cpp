class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        int i=0,j=0;
        int n=arr.size();
        for(j=0;j<n;j++){
            if(arr[j]!=0){
                swap(arr[i],arr[j]);
                i++;
            }
        }
    }
};