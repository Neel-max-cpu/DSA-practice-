class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        
        // if odd number size then even number of paranthesis can't be [not important cause when finding we will get wrong in one place but still]
        if(n%2==1) return false;
        
        stack<char>st;
        int f  = 1;
        for(int i=0; i<n; i++){            
            if(s[i]=='(') st.push(s[i]);
            else{
                // if at start only there is closing bracket then can never be valid
                if(st.empty()) return false;
                
                if(st.top()=='(' && s[i]==')') st.pop();
                else if(st.top()=='{' && s[i]=='}') st.pop();
                else if(st.top()=='[' && s[i]==']') st.pop();
                else return false;
            }
            
        }       
        // at the end all should get popped
        if(st.empty()) 
            return true;
        else return false;    
    }

    void helper(string s, vector<string>&v){
        do{
            if(isValid(s)){
                v.push_back(s);             
            }
        }while(next_permutation(s.begin(), s.end()));
    }

    void make(int n, int open, int close, string s, vector<string>&ans){
        if(open==n && close == n){
            ans.push_back(s);
            return;
        }
        if(close>open) return;
        if(open<n)
            make(n, open+1, close, s+'(', ans);
        if(open>close)
            make(n, open, close+1, s+')', ans);
    }

    vector<string> generateParenthesis(int n) {
        // brute - o(n)+o(n)+(2n*2n!)+o(2n)
        /*
        string s = "";
        for(int i=0; i<n; i++){
            s+='(';
        }
        for(int i=0; i<n; i++){
            s+=')';
        }

        vector<string>ans;
        helper(s, ans);
        for(auto it:ans) cout<<it<<" ";
        return ans;
        */

        // using backtracking - o(2^n)
        vector<string>ans;
        make(n, 0,0,"", ans);
        return ans;
    }
};