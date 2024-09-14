class Solution {
public:       

    int longestSubarray(vector<int>& nums) {
        // brute --
        /*
        int n=nums.size();        
        int max_val = *max_element(nums.begin(), nums.end()); 
        int max_len = 0, current_len = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == max_val) {
                current_len = 1;  
                while (i + 1 < n && (nums[i + 1] & max_val) == max_val) {                    
                    current_len++;
                    i++;
                }
                max_len = max(max_len, current_len);  
            }
        }
        return max_len;
        */

        int n = nums.size();
        int max_val = *max_element(nums.begin(), nums.end());
        int ans = 1;
        int len=0;
        for(int i=0; i<n; i++){
            if(nums[i]==max_val) len++;
            else{
                len = 0;
            }
            ans = max(ans, len);
        }
        return ans;

    }
};