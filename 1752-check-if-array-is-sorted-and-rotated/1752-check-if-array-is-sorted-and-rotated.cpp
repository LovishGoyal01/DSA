class Solution {
public:
    bool check(vector<int>& arr) {
        int n= arr.size();
        int count=0;
        for(int i=1;i<n;i++){
            if(arr[i]<arr[i-1]) count++;
        }
        if(arr[n-1]>arr[0]) count++;
        if(count>=2) return false;
        return true;
    }
};