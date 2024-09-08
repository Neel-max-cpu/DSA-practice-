class Solution {
public:
    string convertDateToBinary(string date) {
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));

        // cout<<year<<" "<<month<<" "<<day<<endl;
        
        string yearBinary = bitset<32>(year).to_string();
        string monthBinary = bitset<8>(month).to_string();
        string dayBinary = bitset<8>(day).to_string();

        // cout<<yearBinary<<" "<<monthBinary<<" "<<dayBinary<<endl;
        
        // int pos = .find('1') - gives the position of the 1st occurance of 1 .substr(pos) everything >=pos
        yearBinary = yearBinary.substr(yearBinary.find('1'));
        monthBinary = monthBinary.substr(monthBinary.find('1'));
        dayBinary = dayBinary.substr(dayBinary.find('1'));

        // cout<<yearBinary<<" "<<monthBinary<<" "<<dayBinary<<endl;

        return yearBinary + "-" + monthBinary + "-" + dayBinary;
    }
};