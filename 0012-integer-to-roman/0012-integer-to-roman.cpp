class Solution {
public:
    string intToRoman(int num) {
        // see constraints 3999

        /*
        string M[] = {"", "M", "MM", "MMM"};
        string C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};   
        string I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};   
        
        string s = M[num/1000] + C[(num%1000)/100] + X[(num%100)/10] + I[num%10];
        return s;
        */
        
        // generic way to solve --
        // keep the main value(M,C,L,D etc) and 1 less value
        vector<pair<int,string>> values = {
            {1000, "M"}, {900,"CM"}, {500, "D"}, {400, "CD"},
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
        };

        string ans = "";
        for(auto [value, symbol]:values){
            while(num>=value){
                num-=value;
                ans+=symbol;
            }
        }
        return ans;
        
    }
};