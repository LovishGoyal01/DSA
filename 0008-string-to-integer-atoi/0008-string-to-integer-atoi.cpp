class Solution {
public:
    int sign = 1;

    long long rec(string &s, int i, long long ans, bool started) {
        if (i >= s.size()) return ans;

        // skip leading spaces
        if (!started && s[i] == ' ')
            return rec(s, i + 1, ans, false);

        // sign handling
        if (!started && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            return rec(s, i + 1, ans, true);
        }

        // digit processing
        if (isdigit(s[i])) {
            started = true;
            ans = ans * 10 + (s[i] - '0');

            // overflow check
            if (sign == 1 && ans > INT_MAX) return INT_MAX;
            if (sign == -1 && -ans < INT_MIN) return INT_MIN;

            return rec(s, i + 1, ans, true);
        }

        // stop if non-digit
        return ans;
    }

    int myAtoi(string s) {
        long long ans = rec(s, 0, 0, false);
        return sign * ans;
    }
};