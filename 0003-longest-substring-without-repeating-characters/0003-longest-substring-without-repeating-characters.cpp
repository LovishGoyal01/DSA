class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,maxi=0;
        map<char,int>mp;
        for(int i=0;i<s.size();i++){
            if(mp.find(s[i])!=mp.end() && mp[s[i]]>=l){
                l=mp[s[i]];
                l++;
            }
            maxi = max(maxi,i-l+1);
            mp[s[i]] = i;
        }
        return maxi;
    }
};