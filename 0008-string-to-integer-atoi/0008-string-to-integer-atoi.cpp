class Solution {
public:
    int myAtoi(string s) {
        int i=0,sign=1;
        int n=s.size();
        while(i<n && s[i]==' ') i++;
        if(i<n && (s[i]=='+' || s[i]=='-')){
            if(s[i]=='-') sign=-1;
            i++;
        }
        long long ans=0,digit;
        while(i<n && (s[i]>='0' && s[i]<='9')){
            digit=s[i]-'0';
            ans=ans*10 + digit;
            if(sign * ans > INT_MAX)
                return INT_MAX;

            if(sign * ans < INT_MIN)
                return INT_MIN;
            i++;
        }
        return sign*ans;
    }
};