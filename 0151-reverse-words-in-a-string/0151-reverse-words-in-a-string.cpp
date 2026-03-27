class Solution {
public:
    string reverseWords(string s) {
        string temp = "", ans = "";

        for(int i = s.size() - 1; i >= 0; i--){
            if(s[i] == ' '){
                if(!temp.empty()){
                    if(!ans.empty()) ans += " ";
                    ans += temp;
                    temp = "";
                }
            } else {
                temp = s[i] + temp;
            }
        }

        if(!temp.empty()){
            if(!ans.empty()) ans += " ";
            ans += temp;
        }

        return ans;
    }
};