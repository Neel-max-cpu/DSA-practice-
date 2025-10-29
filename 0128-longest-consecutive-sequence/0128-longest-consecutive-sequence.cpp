class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // better ig - sorting(nlogn+n)
        //optimized
        unordered_set<int>st(nums.begin(), nums.end());
        int count = 0, longest = 0;
        for(auto it:st){
            int x = it;
            if(st.find(it-1)==st.end()){
                //could be starting                
                count = 1;
                int curr = it;
                while(st.find(curr+1)!=st.end()){
                    //while there are next element
                    count++;
                    curr++;
                }
                longest = max(count, longest);
            }            
        }
        return longest;
    }
};