class Solution {
public:
     void rec(int start,int sum , int k,int n,vector<int>&arr,vector<vector<int>>& ans){
        if(k==0){
            if(sum==n) ans.push_back(arr);
            return;
        }
        for(int i = start;i<=9;i++){
            if(sum+i>n) break;
            sum+=i;
            arr.push_back(i);
            rec(i+1,sum,k-1,n,arr,ans);
            arr.pop_back();
            sum-=i;
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int> arr;
        rec(1,0,k,n,arr,ans);
        return ans;
    }
};