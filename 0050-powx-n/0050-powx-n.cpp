class Solution {
public:
    double calculatePow(double x, long long n){
        if(n==1) return x;

        if(n%2==0){
            //even
            return calculatePow(x*x, n/2);
        }
        else {
            //odd
            double val = calculatePow(x, n-1);
            return x*val;
        }
    }

    double myPow(double x, int n) {
        long long N = n;
        if(n<0) {
            N = (long long)-1 * (long long)n;
            x = 1/x;
        }

        if(n==0) return 1.0;
        if(n==1) return x;

        return calculatePow(x, N);



    }
};