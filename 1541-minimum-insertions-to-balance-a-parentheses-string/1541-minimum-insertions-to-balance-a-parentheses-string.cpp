class Solution {
public:    
    int minInsertions(string s) {        
        // good - o(n) o(n) -- time and space(although space can be removed)
        /*
        stack<char>st;
        int open =0, close = 0;
        int i = 0;
        while(i<s.size()){
            char it = s[i];
            if(it=='('){
                st.push(it);
            }
            else if(it==')'){                
                if(st.empty()){
                    if(i+1<s.size() && s[i+1]==')'){
                        // since close balanced
                        open++;
                        i++;
                    }
                    else{
                        // 1 open, 1 close needed
                        close++;
                        open++;
                    }
                }
                else if(!st.empty()){
                    if(i+1<s.size() && s[i+1]==')'){
                        // balanced
                        st.pop();
                        i++;
                    }
                    else{
                        // 1 close needed
                        st.pop();
                        close++;
                    }
                }
            }
            i++;
        }
        int total = open+close;
        if(st.size()>0){
            total = total + 2*st.size();
        }
        return total;
        */

        // optimal -- o(n) & o(1)
        int open = 0;
        int insertion = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='('){
                open++;
            }
            else{
                // check pair
                if(i+1<s.size() && s[i+1]==')'){                    
                    // since close balanced
                    i++;
                }
                else{
                    // we hypothetically insert one more to make it balance
                    insertion++;
                }

                if(open>0){
                    // balanced so we can reduce
                    open--;
                }
                else{
                    // insert an '(' since we already have balanced closing - '))'
                    insertion++;
                }
            }
        }

        // since each open need 2 closing - '))'
        return insertion+2*open;
    }
};