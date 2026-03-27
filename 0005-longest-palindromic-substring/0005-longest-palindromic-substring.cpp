class Solution {
public:
    string longestPalindrome(string str) {
        string LPS = string(1,str[0]);
        int low,high;
        int n=str.size();

        for(int i=0;i<n;i++){
           // For Odd
            low=i;
            high=i;
           while(low>=0 && high<n && str[low]==str[high]){
             low--;
             high++;
           } 
           string pallindrom = str.substr(low+1,high-low-1);
           if(pallindrom.size()>LPS.size()) LPS = pallindrom;

           // for even
           low=i-1;
            high=i;
           while(low>=0 && high<n && str[low]==str[high]){
             low--;
             high++;
           } 
           pallindrom = str.substr(low+1,high-low-1);
           if(pallindrom.size()>LPS.size()) LPS = pallindrom;
        }
        return LPS;
    }
};