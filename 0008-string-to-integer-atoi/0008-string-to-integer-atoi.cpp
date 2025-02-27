class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int sign = 1;
        long ans = 0;
        
        // remove starting spaces
        while(i<s.size() && s[i]==' ')
            i++;    
        
        if(s[i]=='-'){
            sign = -1;
            i++;
        }
        else if(s[i]=='+'){
            i++;
        }
        while(i<s.size()){
            if(s[i]>='0' && s[i]<='9'){
                ans = ans*10+(s[i]-'0');
                if(ans>INT_MAX && sign == -1) return INT_MIN;
                else if(ans>INT_MAX && sign == 1) return INT_MAX;
                i++;
            }
            // if found another char
            else return ans*sign;
        }
        return ans*sign;
    }
};