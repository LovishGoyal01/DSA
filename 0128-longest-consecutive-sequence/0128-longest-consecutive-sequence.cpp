class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>sett;
        int n= nums.size();
        int maxi=0;

        for(int i=0;i<n;i++) sett.insert(nums[i]);

        for(auto it : sett){
            if(sett.find(it-1)==sett.end()){
                int cnt=1;
                int x=it;
                while(sett.find(x+1)!=sett.end()){
                    cnt++;
                    x++;
                }
                maxi = max(maxi,cnt);
            }
        }
        return maxi;
    }
};