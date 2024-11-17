class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();        
        if(k>n) k = k%n;

        // using extra space ---
        /*
        vector<int>temp(n);

        // copy the last k ele
        for(int i=0; i<k; i++){
            temp[i] = nums[n-k+i];
        }

        // copy the first k ele
        for(int i=k; i<n; i++){
            temp[i]=nums[i-k];
        }
        nums = temp;
        */

        // using reverse
        reverse(nums.begin(), nums.end());

        // reverse the first k 
        reverse(nums.begin(), nums.begin()+k);

        // reverse the last k
        reverse(nums.begin()+k, nums.end());    

    }
};