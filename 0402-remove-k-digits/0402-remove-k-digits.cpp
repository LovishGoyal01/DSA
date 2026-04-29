class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;

        for(char ch : num){
            while(!st.empty() && k > 0 && st.top() > ch){
                st.pop();
                k--;
            }
            st.push(ch);
        }

        // remove remaining k digits from end
        while(k > 0 && !st.empty()){
            st.pop();
            k--;
        }

        // build string
        string str = "";
        while(!st.empty()){
            str = st.top() + str;
            st.pop();
        }

        // remove leading zeros
        int i = 0;
        while(i < str.size() && str[i] == '0') i++;

        str = str.substr(i);

        return str.empty() ? "0" : str;
    }
};