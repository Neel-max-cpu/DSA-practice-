class Solution {
public:
    int findDuplicate(vector<int>& arr) {
        int n = arr.size();
        //modified -- not allowed
        /*
        int i = 0;
        while(true){            
            int x = arr[i];
            if(x==-1) return i;
            arr[i] = -1;
            i = x;
        }
        */
        int fast = 0;
        int slow = 0;
        // use do while since using while it would never run
        do{
            slow = arr[slow];           //moves once
            fast = arr[arr[fast]];      //moves twice
        }while(slow!=fast);        
        //here now slow == fast
        // now reset fast to 0(or slow since both are equal) and move both by one step until they meet again
        fast = 0;
        while(fast!=slow){
            slow = arr[slow];
            fast = arr[fast];
        }
        return slow;
    }
};