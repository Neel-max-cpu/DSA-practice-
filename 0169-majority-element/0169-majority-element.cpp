class Solution {
public:
    int majorityElement(vector<int>& arr) {
        // better hashmap o(n) + o(n)
        //best --
        int curr = 0;
        int count = 0;
        for(auto it:arr){
            if(count==0){
                curr = it;
                count = 1;
            }
            else{
                if(curr == it){
                    count++;
                }
                else {
                    count--;                
                }
            }
        }
        return curr;
    }
};