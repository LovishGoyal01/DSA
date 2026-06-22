class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int b=0,a=0,l=0,o=0,n=0;
        for(char ch:text){
            if(ch=='b') b++;
            if(ch=='a') a++;
            if(ch=='l') l++;
            if(ch=='o') o++;
            if(ch=='n') n++;
        }
        l=l/2;
        o=o/2;
    return min(a,min(b,min(l,min(o,n))));
    }
};