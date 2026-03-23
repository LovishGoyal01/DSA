class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        int n=arr.size();
        int j=-1;
        for(int i=0;i<n;i++){
            if(j==-1 && arr[i]==0){
                j=i;
            }
            else if(j!=-1 && arr[i]!=0){
                arr[j]=arr[i];
                j++;
                arr[i]=0;
            }
        }
       
    }
};