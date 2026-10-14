class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
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
    }
};