class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> mp;
        int l=0,maxl=0;
        for(int r=0;r<s.size();r++){
           if(mp.find(s[r])!=mp.end() && mp[s[r]]>=l) l=mp[s[r]]+1;
            maxl = max(maxl,r-l+1);
            mp[s[r]]=r;
        }
        return maxl;
    }
};