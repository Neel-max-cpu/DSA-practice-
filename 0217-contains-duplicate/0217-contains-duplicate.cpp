class Solution {
public:    
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int>st;        
        for(auto it:nums){
            if(st.find(it)!=st.end()){
                // if found --
                return true;
            }
            else {
                // not found
                st.insert(it);                                
            }
        }        
        return false;
    }
};