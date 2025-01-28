class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = goal.size();
        int m = s.size();
        if(n!=m) return false;

        if(s==goal) return true;
        int i=1;
        string t = "";
        while(i<n){
            t.clear();
            t += s.substr(i, n-i);
            t += s.substr(0,i);            
            if(t==goal) return true;
            i++;
        }   
        return false;

    }
};