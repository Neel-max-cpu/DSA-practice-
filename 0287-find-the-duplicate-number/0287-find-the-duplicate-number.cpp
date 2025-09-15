class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();

        int slow = nums[0];
        int fast = nums[0];
        do{
            // move the slow pointer by 1 and fast pointer by 2
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        while(slow!=fast);

        fast = nums[0];
        while(slow!=fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;



        /*
        vector<int>v(n+1, 0);
        // for(int i=0; i<n+1; i++){
        //     v[i] = i;
        // }
        int ans = 0;
        for(int i=0; i<n; i++){
            int x = nums[i];
            // if(v[x] == x){
            //     v[x] = 0;
            // }
            // else{
            //     ans = x;
            //     break;
            // }
            if(v[x] ==0 ) v[x] = 1;
            else if(v[x]==1){
                ans = x;
                break;
            }
        }
        return ans;
        */
        
    }
};