class Solution {
public:
    bool check(string& s,int start,int end){
        if(start>=end) return true;
        if(!isalnum(s[start])) return check(s,start+1,end);
        if(!isalnum(s[end])) return check(s,start,end-1);

        if(tolower(s[start])==tolower(s[end])) return check(s,start+1,end-1);
        return false;
    }
    bool isPalindrome(string s) {
       int n=s.size(); 
       return check(s,0,n-1); 
    }
};