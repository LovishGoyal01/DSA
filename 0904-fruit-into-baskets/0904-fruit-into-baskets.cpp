class Solution {
public:
    int totalFruit(vector<int>& fruits) {
       map<int,int>mp;
       int i=0,l=0,maxi=0;
       int n = fruits.size();
       while(i<n){
        mp[fruits[i]]++;
        if(mp.size()>2){
            mp[fruits[l]]--;
            if(mp[fruits[l]]==0) mp.erase(fruits[l]);
            l++;
        }
        if(mp.size()<=2) maxi = max(maxi,i-l+1);
        i++;
       } 
       return maxi;
    }
};