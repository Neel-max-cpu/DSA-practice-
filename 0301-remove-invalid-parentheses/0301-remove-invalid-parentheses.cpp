class Solution {
public:
    bool isValid(string &s){
        int open = 0;
        for(auto it:s){
            if(open<0) return false;

            if(it=='(') open++;
            else if(it==')'){
                if(open>0) open--;
                else return false;
            }
        }

        return open==0? true:false;
    }    
    int getMinCount(string &s){
        // extra open + close
        int open = 0, close = 0;
        for(auto it:s){
            if(it=='('){
                open++;
            }
            else if(it==')'){
                if(open>0) open--;
                else{
                    close++;
                    open = 0;
                }
            }
        }
        return open+close;
    }

    void helper(string &s, int i, string &t, set<string>&res, int minRemoval){
        if(i==s.size()){            
            if(isValid(t)){
                res.insert(t);
            }
            return;
        }

        if(s[i]=='(' || s[i]==')'){
            // can remove -- dont add in t
            if(minRemoval>0){
                helper(s, i+1, t, res, minRemoval-1);
            }
        } 
        // or skip -- add in t and keep going
        t.push_back(s[i]);
        helper(s, i+1, t, res, minRemoval);
        t.pop_back();
    }

    vector<string> removeInvalidParentheses(string s) {
        int n = s.size();        
        if(isValid(s)) return {s};            
        set<string>res;
        string t="";
        int minRemoval = getMinCount(s);
        helper(s, 0, t, res, minRemoval);                

        vector<string>ans(res.begin(), res.end());
        return ans;
    }
};