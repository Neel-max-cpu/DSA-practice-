class Solution {
public:
    bool isHappy(int n) {
        long long sum = n;
        set<long long>s;
        s.insert(n);
        while(sum!=1){
            long long val = 0;
            while(n>0){
                int temp = n%10;
                val += (temp*temp);
                n/=10;
            }
            sum = val;
            n=val;
            // found cycle
            if(s.find(sum)!=s.end()) return false;
            else {
                if(val>INT_MAX) return false;
                s.insert(val);
            }
        }
        return true;
        
    }
};