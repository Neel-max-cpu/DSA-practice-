class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int i = 0;
        while(s[i]==' ') i++;
        
        int sign = 1;
        if(s[i]=='-') {
            sign = -1;
            i++;
        }
        else if(s[i]=='+') i++;

        long val = 0;
        bool first = true;
        while(i<n){
            if(s[i]>='0' && s[i]<='9') {
                if(!first) val*=10;
                val+=s[i]-'0';   
                if(val>=INT_MAX) break;
                first = false;           
            }
            else break;
            i++;
        }
        if(val>=INT_MAX){            
            if(sign==1) return INT_MAX;
            else{
                if(val*sign > INT_MIN) return val*sign;
                else return INT_MIN;
            }            
        }
        else{
            return sign==1? val : val*sign;
        }
    }
};