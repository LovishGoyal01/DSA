class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& arr) {
      int cnt=0,maxi=0;;
      for(int i=0;i<arr.size();i++){
        if(arr[i]==1){
            cnt++;
            maxi = max(maxi,cnt);
        }else cnt=0;
      }  
      return maxi;
    }
};