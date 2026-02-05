class Solution {
public:
    int get10s(int num, int len){
        int value = 1;
        for(int i=0; i<len-1; i++){
            value*=10;
        }
        return value;
    }

    string intToRoman(int num) {
        unordered_map<int,string>m;
        m[1] = "I";
        m[2] = "II";
        m[3] = "III";
        m[4] = "IV";
        m[5] = "V";
        m[6] = "VI";
        m[7] = "VII";
        m[8] = "VIII";
        m[9] = "IX";
        
        m[10] = "X";
        m[20] = "XX";
        m[30] = "XXX";
        m[40] = "XL";
        m[50] = "L";
        m[60] = "LX";
        m[70] = "LXX";
        m[80] = "LXXX";
        m[90] = "XC";

        m[100] = "C";
        m[200] = "CC";
        m[300] = "CCC";
        m[400] = "CD";
        m[500] = "D";
        m[600] = "DC";
        m[700] = "DCC";
        m[800] = "DCCC";
        m[900] = "CM";
        
        m[1000] = "M";
        m[2000] = "MM";
        m[3000] = "MMM";

        string ans;
        while(num>0){
            string s = to_string(num);
            int diffValue = get10s(num, s.size());
            // 3749 then diffValue = 1000, so left = 3
            int left = num/diffValue;
            int totalVal = left*diffValue;
            ans+=m[totalVal];  

            // 3749 then new num = 3749%1000 = 749
            num = num%diffValue;
        }
        return ans;
    }
};