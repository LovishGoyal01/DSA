class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        map<int,int>mpp;
        int rem = 0;
        for(int i=0;i<arr.size();i++){
            rem = target-arr[i];
            if(mpp.find(rem)!=mpp.end()){
                return {mpp[rem],i};
            }
            mpp[arr[i]]=i;
        } 
        return {-1,-1};
    }
};