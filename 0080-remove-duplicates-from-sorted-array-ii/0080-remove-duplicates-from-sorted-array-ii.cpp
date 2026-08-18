class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       map<int,int>mp;
       int count=0;
       for(int i=0;i<nums.size();i++){
        mp[nums[i]]++;
        if(mp[nums[i]]<=2){
            nums[count]=nums[i];
            count++;
        } 
       } 
       return count;

    }
};