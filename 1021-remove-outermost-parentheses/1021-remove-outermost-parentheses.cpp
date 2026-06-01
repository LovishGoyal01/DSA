class Solution {
public:
    string removeOuterParentheses(string s) {
       string st="";
       int count=0;
       for(char ch:s){
         if(ch=='('){
            count++;
            if(count==1) continue;
            else st+=ch; 
         }else if(ch==')'){
            count--;
            if(count==0) continue;
            else st+=ch;
         }
       }
       return st; 
    }
};