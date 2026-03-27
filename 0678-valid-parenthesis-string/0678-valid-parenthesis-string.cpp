// class Solution {
// public:
//     bool checkValidString(string s) {
//         int count=0,star=0;
//         for(int i=0;i<s.size();i++){
//             if(s[i]=='(') count++;
//             else if(s[i]==')') count--;
//             else if(s[i]=='*') star++;
//         } 
//         if(count==0 || star+count==0 || star-count==0) return true;
//         return false;
//     }
// };

class Solution {
public:
    bool checkValidString(string s) {
        int low = 0, high = 0;

        for(char ch : s) {
            if(ch == '(') {
                low++;
                high++;
            }
            else if(ch == ')') {
                low--;
                high--;
            }
            else { // '*'
                low--;     // treat as ')'
                high++;    // treat as '('
            }

            // invalid case
            if(high < 0) return false;

            // low should not go below 0
            if(low < 0) low = 0;
        }

        return low == 0;
    }
};