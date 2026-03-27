class Solution {
public:
    string reverseWords(string s) {
        stack<string>st;
        string ans="";
        for(auto it : s){
            if(it==' '){
                if(ans.empty()) continue;
                st.push(ans);
                ans = "";
            }else {
                ans+=it;
            }
        }
        if(ans.size()>=1) st.push(ans);
        ans="";
        while(!st.empty()){
           if(!ans.empty())ans=ans+ " " +st.top();
           else ans+=st.top();
           st.pop();
        }
     return ans;
    }
};