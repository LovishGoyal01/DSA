class Solution {
public:
    double myPow(double x, int n) {
       long long N = n;
       if(n>0) return  myPowA(x,N);
       return myPowA(1/x,-N);
    }
    double myPowA(double x, int n) {
       if(n==0) return  1.0;
       double half=myPowA(x,n/2);
       if(n%2==0) return half*half;
       return half*half*x; 
    }
};