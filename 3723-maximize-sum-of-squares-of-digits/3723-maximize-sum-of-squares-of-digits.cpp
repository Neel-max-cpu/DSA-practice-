class Solution {
public:
    string maxSumOfSquares(int num, int sum) {

        // optimal --
        if (sum > 9 * num) return "";
        
        string s;
        while (num > 0) {
            int digit = min(9, sum);
            s.push_back('0' + digit);
            sum -= digit;
            num--;
        }

        return sum == 0 ? s : "";

        // mine ---
        /*
        string s;
        int total = 0;
        int i = 9; 
        int k = sum;       
        while(num>0){
            if(i<=k){
                s.push_back(i+'0');
                total+=i;
                k-=i;
                num--;
            }
            else {
                i--;
                if(i<0) i=0;
            }
        }
        if(total == sum) return s;
        else return "";
        */
    }
};