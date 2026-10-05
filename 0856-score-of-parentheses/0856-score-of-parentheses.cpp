class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<pair<int,int>>number;
        stack<pair<char,int>>open;
        int level = 1;
        for(int i=0; i<s.size(); i++){
            char it = s[i];
            if(it=='('){
                open.push({'(',level});
                level++;
            }
            else{
                level--;
                if(number.empty())
                    number.push({1,level});
                else if(!number.empty() && number.top().second <= level)
                    number.push({1,level});
                else{
                    // add the stack then mul by 2
                    int sum = 0;
                    while(!number.empty() && number.top().second>level){
                        auto x = number.top();
                        number.pop();
                        sum+=x.first;
                    }
                    sum = sum*2;
                    number.push({sum, level});
                }
            }
        }
        if(number.size()==1)        
            return number.top().first;
        else{
            int sum = 0;
            while(!number.empty()){
                sum += number.top().first;
                number.pop();
            }
            return sum;
        }
    }
};

