class Solution {
public:
    vector<int>helper(string s){
        vector<int>ans;
        for(int i=0; i<s.size();i++){
            if(s[i]=='+' || s[i]=='-' || s[i]=='*'){
                vector<int>leftv = helper(s.substr(0, i));
                vector<int>rightv = helper(s.substr(i+1));

                for(auto left:leftv){
                    for(auto right:rightv){
                        if(s[i]=='+')
                            ans.push_back(left+right);                        
                        else if(s[i]=='-')
                            ans.push_back(left-right);
                        else if(s[i]=='*')
                            ans.push_back(left*right);
                    }
                }
            }
        }

        if(ans.empty()){
            ans.push_back(stoi(s));
        }
        return ans;
    }
    vector<int> diffWaysToCompute(string expression) {        
        return helper(expression);
    }
};