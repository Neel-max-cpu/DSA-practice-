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

    vector<string> generateParenthesis(int n) {
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
    }
};