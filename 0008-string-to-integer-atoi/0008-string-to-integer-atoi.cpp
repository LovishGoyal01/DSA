class Solution {
public:
    int rec(string& s,int i,int sign,bool started,int ans){
        if(i >= s.size()) return sign * ans;

        if(!started && s[i]==' ')
            return rec(s,i+1,sign,started,ans);

        if(!started && (s[i]=='-' || s[i]=='+')){
            if(s[i]=='-') sign=-1;
            return rec(s,i+1,sign,true,ans);
        }

        if(s[i]>='0' && s[i]<='9'){
            int digit=s[i]-'0';

            if(ans > (INT_MAX - digit)/10)
                return sign==1 ? INT_MAX : INT_MIN;

            ans = ans*10 + digit;

            return rec(s,i+1,sign,true,ans);
        }

        return sign * ans;
    }

    int myAtoi(string s) {
        return rec(s,0,1,false,0);
    }
};