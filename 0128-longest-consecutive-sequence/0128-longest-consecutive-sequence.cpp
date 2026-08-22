class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        int n = arr.size();
        if(n==0) return 0;
        unordered_set<int>s(arr.begin(), arr.end());        

        int ans = 0;
        for(auto it:s){
            if(s.find(it-1)==s.end()){
                // if prev not found could be starting
                int count = 1;
                int x = it;
                while(s.find(x+1)!=s.end()){
                    x = x+1;
                    count++;
                }
                ans = max(ans, count);
            }
        }
        return ans;
    }
};