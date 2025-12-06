class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();

        // optimised binary search --
        /*
        1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6 -- eg
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
        see -- generally its even odd same number, 0=1(1); 2=3(2); 4=5(3);
        but when a single element is occured then it become reversed 7=8(5); 9=10(6);
        so even=odd if left half and odd=even if right half in binary search
        that's why mid%2==0 if mid index is even check for i+1(odd) and if mid+2==1 if mid index is odd check for i-1(even) to check for 
        the left half, cause left half genearlly stays the same and we know the single element is in the righ half so low = mid+1;
        */

        // edge cases, if size=1, first ele and last ele
        if(n==1) return nums[0];
        if(nums[0]!=nums[1]) return nums[0];
        if(nums[n-1]!=nums[n-2]) return nums[n-1];

        int low = 1;
        int high = n-2;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]) return nums[mid];
            else{
                if((mid%2==0 && nums[mid]==nums[mid+1]) || (mid%2==1 && nums[mid]==nums[mid-1])) low = mid+1;
                else high = mid-1;
            }
        }
        return -1;


        // using xor  a^a = 0 and a^0 = a;
        // so what will happen ---
        /*
        1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6 -- eg
        0 ^1 = 1; 1^1 = 0; then again 0^2 = 2; 2^2 = 0; then again 0^3 = 3; 3^3 = 0;
        then again 0^4 = 4; 4^5(lets keep it without finding the value); then 4^5^5 = 4(since 5^5 cancel);
        then 4^6 = 4^6; then 4^6^6 = 4 again so return 4 done;
        */
        /*
        int ans = 0;
        for(int i = 0;i <n; i++){
            ans = ans^nums[i];
        }
        return ans;
        */
        // brute
        /*
        if(n==1) return nums[0];
        for(int i=0; i<n; i++){
            // first index
            if(i==0) {
                if(nums[i]!=nums[i+1]) return nums[i];
            }
            // last index
            else if(i==n-1){
                if(nums[i]!=nums[i-1]) return nums[i];
            }

            else{
                if(nums[i]!=nums[i-1] && nums[i]!=nums[i+1]) return nums[i];
            }
        }
        return -1;
        */

        // bruh solution --
        /*
        if(n==1) return nums[0];
        int count = 1;
        int ans = 0;
        for(int i=1; i<n; i++){
            if(nums[i]!=nums[i-1]){
                // cout<<i<<" "<<count<<endl;
                if(count==2){
                    count = 1;
                    // continue;
                }
                else if(count==1){
                    count = 0;
                    ans = nums[i-1];
                    break;
                }
            }
            else count++;
        }
        if(count==1) ans = nums[n-1];
        return ans;
        */
    }
};