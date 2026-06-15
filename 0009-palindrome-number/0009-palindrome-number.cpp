class Solution {
public:
    bool isPalindrome(int x) {
       int z=x;
       long digit=0; 
       while(z>0){
         digit=digit*10+ z%10;
         z=z/10;
       }
       return x==digit; 
    }
};