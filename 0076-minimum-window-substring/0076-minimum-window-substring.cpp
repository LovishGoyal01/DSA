class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int>mpp;
        int l=0,r=0,minl=INT_MAX,sindex=-1;
        int cnt=0;
        int m=t.size();
        int n=s.size();
        for(int i=0;i<m;i++){
            mpp[t[i]]++;
        }

        while(r<n){
            if(mpp[s[r]]>0) cnt++;
            mpp[s[r]]--;
            while(cnt==m){
                if(r-l+1 < minl){
                    minl=r-l+1;
                    sindex=l;
                }    
                mpp[s[l]]++;
                if(mpp[s[l]]>0) cnt--;
                l++;
            }
            r++;
        }
        return sindex==-1?"":s.substr(sindex,minl);
    }
};