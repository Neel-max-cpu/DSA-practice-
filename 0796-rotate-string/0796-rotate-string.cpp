class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = goal.size();
        int m = s.size();
        if(n!=m) return false;

        // brute force ---
        /*
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
        */

        // brute force ---
        /*
        for(int i=0; i<n; i++){
            rotate(s.begin(), s.begin()+1, s.end());
            if(s==goal) return true;
        }
        return false;
        */

        // BETTER method -- o(n)
        // /*
        string doublestring = s+s;

        // .find in substring returs the first index when the substring is found
        // int x = doublestring.find(goal);
        // if(x!=string::npos) {
        //     cout<<"pos: "<<x<<endl;
        //     return true;
        // }
        // else return false;

        // OR -- since .find returns the pos so, if found then it should be < length of the double string
        return doublestring.find(goal) < doublestring.size();
        // */


        // best -- kmp algo o(n) but not need

    }
};