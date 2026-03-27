class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n=s.size();
        int m=t.size();
        if(n!=m) return false;
        map<char,char>mpp;
        set<char>st;
        for(int i=0;i<n;i++){
            if(mpp.find(s[i])!=mpp.end()){
                if(mpp[s[i]]!=t[i]) return false;
            }else{
                if(st.find(t[i])!=st.end()) return false;
                mpp[s[i]]=t[i];
                st.insert(t[i]);
            }
        }
        return true;
    }
};