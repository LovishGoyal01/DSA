class Solution {
public:
    void solve(string digits,int i,int& n,string s,vector<string>& ans, vector<string>& mp){
        if(i>=n){
            ans.push_back(s);
            return;
        }
        string chars = mp[digits[i]-'0'];
        for(char ch:chars){
            solve(digits,i+1,n,s+ch,ans,mp);
        }
    }

    vector<string> letterCombinations(string digits) {
      if (digits.empty()) return {};
    
        vector<string> mp = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        int n=digits.size();
        vector<string> ans;
        solve(digits,0,n,"", ans, mp);

        return ans;  
    }
};