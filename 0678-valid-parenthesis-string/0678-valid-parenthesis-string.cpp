class Solution {
public:
    bool checkValidString(string s) {
        stack<pair<char,int>>open;        
        stack<pair<char,int>>star;
        for(int i=0; i<s.size(); i++){
        // for(auto it:s){
            char it = s[i];
            if(it=='(') open.push({it,i});
            else if(it=='*') star.push({it,i});
            else if(it==')'){
                if(!open.empty()) open.pop();
                else if(!star.empty()) star.pop();
                else return false;
            }
        }

        if(open.empty()) return true;
        else {
            // how many unbalanced we can - for every open '(' we must have a '*' towareds the right
            while(!open.empty()){
                if(!star.empty() &&  star.top().second > open.top().second) {                    
                    open.pop();          
                    star.pop();
                }
                else return false;
            }            
            return true;
        }
    }
};