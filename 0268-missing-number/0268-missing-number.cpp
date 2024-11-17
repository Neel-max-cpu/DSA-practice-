class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        /*
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++){
            if(nums[i]!=i) return i;
        }
        return n;
        */


        /*
        vector<int>v(n+1,-1);
        for(int i=0; i<n; i++){
            v[nums[i]] = 1;
        }

        for(int i=0; i<n+1; i++){
            if(v[i]==-1) return i;
        }
        // temp return
        return -1;
        */


        // optimial ---
        /*
        int sum = n*(n+1)/2;
        int count = 0;
        for(auto it:nums){
            count+=it;
        }
        return sum-count;
        */


        // same using xor a^a = 0, so 
        // so xor1 is the xor from 0 to n
        // xor2 should be the xor of all the ele form the array
        // so xor1 ^ xor2 would give us the missing number

        int xor1 = 0, xor2 = 0;
        for(int i=0; i<n; i++){
            xor1^=i;
            xor2^=nums[i];
        }
        xor1^=n;
        return xor1^xor2;
    }
};