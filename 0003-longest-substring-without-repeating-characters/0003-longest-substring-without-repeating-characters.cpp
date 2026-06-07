class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,r=0;
        map<char,int> mpp;
        int maxl=0;
        while(r<s.size()){
            if(mpp.find(s[r])!=mpp.end() && mpp[s[r]]>=l){
             l=mpp[s[r]]+1;
            }
            maxl=max(maxl,r-l+1);
            mpp[s[r]]=r;
            r++;
        }
        
        return maxl;
    }
};