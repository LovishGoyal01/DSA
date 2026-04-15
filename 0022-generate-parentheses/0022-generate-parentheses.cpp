class Solution {
public:

    void generateP(string s , int open ,int closed,vector<string>& ans){
        if(open==0 && closed==0) return ans.push_back(s);
        if(open>0) generateP(s+'(',open-1,closed,ans);
        if(closed > open && closed>0) generateP(s+')',open,closed-1,ans);
        return;
    }

    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string s = "";
        generateP(s,n,n,ans);
        return ans;
    }
};