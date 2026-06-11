class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
       sort(g.begin(),g.end());
       sort(s.begin(),s.end());
       int r=0,l=0;
       int m=s.size();
        while(l<m){
            if(r<g.size() && g[r]<=s[l]) r++;

            l++;
        }
        return r;
    }
};