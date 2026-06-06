class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;

        for(char ch : num){
            while(!st.empty() && st.top() > ch && k > 0){
                st.pop();
                k--;
            }
            st.push(ch);
        }

        while(k > 0){
            st.pop();
            k--;
        }

        string ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        int i = 0;
        while(i < ans.size() && ans[i] == '0')
            i++;

        if(i == ans.size())
            return "0";

        return ans.substr(i);
    }
};