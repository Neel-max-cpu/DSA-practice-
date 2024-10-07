class Solution {
public:
    int minLength(string s) {     

        // method 1 --
        /*   
        stack<char>st;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='B'){
                if(!st.empty() && st.top()=='A') st.pop();
                else st.push(s[i]);
            }
            else if(s[i]=='D'){
                if(!st.empty() && st.top()=='C') st.pop();
                else st.push(s[i]);
            }
            else st.push(s[i]);
            
        }
        return st.size();
        */

        // method 2 ---
        int i=0;        
        while(i<s.size()){
            string t = s.substr(i,2);
            if(t=="AB" || t == "CD") {
                s.erase(i,2); 
                i=0;
                cout<<s<<endl;               
            }
            else 
                i++;
            
        }
        return s.size();
    }
};