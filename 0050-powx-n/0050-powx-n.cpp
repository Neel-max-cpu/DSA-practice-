class Solution {
public:
    double myPow(double x, int n) {
        // return pow(x, n);
        long long nn = n;
        double ans = 1.0;
        if(n<0){
            nn *= -1;
        }

        while(nn>0){
            if(nn%2==0){
                // if even square
                x = x*x;
                nn/=2;
            }
            else{
                //if odd
                ans *=x;
                nn--;
            }
        }
        if(n<0) return double(1.0)/ans;
        else return ans;

    }
};