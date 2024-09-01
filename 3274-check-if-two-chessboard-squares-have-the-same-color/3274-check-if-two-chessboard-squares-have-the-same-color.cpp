class Solution {
public:
    bool checkTwoChessboards(string s1, string s2) {
        set<char>even;
        even.insert('a');
        even.insert('c');
        even.insert('e');
        even.insert('g');
        set<char>odd;
        odd.insert('b');
        odd.insert('d');
        odd.insert('f');
        odd.insert('h');

        int x = s1[1]-'0';
        int y = s2[1] - '0';

        if(even.find(s1[0])!=even.end()){
            // if found
            if(even.find(s2[0])!=even.end()){
                if(x%2==y%2) return true;
                else return false;
            }
            else{
                if(x%2!=y%2) return true;
                else return false;
            }            
        }
        else{
            // not found
            if(odd.find(s2[0])!=odd.end()){
                if(x%2==y%2) return true;
                else return false;
            }
            else{
                if(x%2!=y%2) return true;
                else return false;
            }
            
        }
        return false;
    }
};