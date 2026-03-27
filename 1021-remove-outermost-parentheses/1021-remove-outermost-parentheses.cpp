class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int cnt=0;
        for(auto it:s){
            if(it=='('){
             cnt++;
             if(cnt>1) ans+=it;
            } 
            else{
                if(cnt>1) ans+=it;
                cnt--; 
            }
            
            
        }
        return ans;
    }
};