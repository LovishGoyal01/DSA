class Solution {
public:
    void sortColors(vector<int>& arr) {
        int l=0,r=arr.size()-1,i=0;
        while(i<=r){
            if(arr[i]==0){
                swap(arr[i],arr[l]);
                i++;
                l++;
            }
            else if(arr[i]==2){
                swap(arr[i],arr[r]);
                r--;
            }else{
                i++;
            }
        }

    }
};