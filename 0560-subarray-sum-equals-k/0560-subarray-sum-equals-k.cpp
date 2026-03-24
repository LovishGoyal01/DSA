class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
     int n= nums.size();
     map<int,int>mapp;
     int cnt=0,sum=0;
     mapp[0]=1;
     for(int i=0;i<n;i++){
        sum+=nums[i];
        int rem=sum-k;
        if(mapp.find(rem)!=mapp.end()) {
            cnt+=mapp[rem];
        }
        mapp[sum]++;
     } 
     return cnt;  
    }
};