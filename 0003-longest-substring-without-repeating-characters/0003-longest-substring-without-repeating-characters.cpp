class Solution {
public:
    int lengthOfLongestSubstring(string input) {
        int n = input.size();
        /*
        int ans = 0;
        for(int i=0; i<n; i++){
            set<char>s;
            int count = 0;
            for(int j=i; j<n; j++){
                // if not found
                if(s.find(input[j]) == s.end()){
                    s.insert(input[j]);
                    count++;
                }
                // if found
                else{
                    break;
                }
            }
            ans = max(ans, count);
        }
        return ans;
        */

        // better ---- 

        /*
        int ans =0;
        int left = 0, right = 0;
        set<char>s;
        for(int right = 0; right<n; right++){
            if(s.find(input[right])!=s.end()){
                // if found
                while(left<right && s.find(input[right])!=s.end()){
                    s.erase(input[left]);
                    left++;
                }
            }
            // not found
            ans = max(ans, right-left+1);
            s.insert(input[right]);
        }
        return ans;
        */

            //    best -- 
    // /*


        vector<int>v(256, -1);
        // vector<char>v(256, -1);
        // map<char,int>v;
        int left = 0;
        int ans = 0;
        int right = 0;
        while(right<n){
            if(v[input[right]] != -1){
            // if(v.find(input[right]) != v.end()){
                // alread present
                // take the right + 1 since we have to update the left to that place
                left = max(v[input[right]] + 1, left);
            }
            // if not found/even if found update the index
            v[input[right]] = right;
            ans = max(ans, right-left+1);
            right++;
        }
        return ans;
        // */
    }
};