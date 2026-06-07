class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        map<char,int>mpp;
        int l=0,r=0,maxF=0,maxl=0;
        while(r<n){
            mpp[s[r]]++;
            maxF=max(maxF,mpp[s[r]]);
            if(r-l+1 - maxF>k){
                mpp[s[l]]--;
                if(mpp[s[l]]==0) mpp.erase(mpp[s[l]]);
                l++;
            }
            if((r-l+1)-maxF<=k){
                maxl=max(maxl,r-l+1);
            }
            r++;
        }
        return maxl;
    }
};