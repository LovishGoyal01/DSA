class Solution {
public:
    int divide(int dividend, int divisor) {
    if(divisor == 0) return INT_MAX;  // Edge case
    if(dividend == INT_MIN && divisor == -1) return INT_MAX;
    
    int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
    
    long long n = llabs((long long)dividend);
    long long d = llabs((long long)divisor);
    long long ans = 0;
    
    while(n >= d) {
        long long cnt = 0;
        while(n >= (d << (cnt + 1))) {
            cnt++;
        }
        ans += (1LL << cnt);
        n -= (d << cnt);
    }
    
    return (int)(sign * ans);
}
};