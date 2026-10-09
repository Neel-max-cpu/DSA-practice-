class Solution {
public:    
    int minInsertions(string s) {        
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
    }
};