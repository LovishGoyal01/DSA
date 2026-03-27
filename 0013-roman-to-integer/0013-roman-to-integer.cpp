class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        char prev = ' ';
        
        for(char ch : s) {
            int val = 0;
            
            if(ch=='M') val = 1000;
            else if(ch=='D') val = 500;
            else if(ch=='C') val = 100;
            else if(ch=='L') val = 50;
            else if(ch=='X') val = 10;
            else if(ch=='V') val = 5;
            else val = 1;

            ans += val;

            // subtractive cases
            if(prev == 'I' && (ch == 'V' || ch == 'X')) ans -= 2;
            if(prev == 'X' && (ch == 'L' || ch == 'C')) ans -= 20;
            if(prev == 'C' && (ch == 'D' || ch == 'M')) ans -= 200;

            prev = ch;
        }
        
        return ans;
    }
};