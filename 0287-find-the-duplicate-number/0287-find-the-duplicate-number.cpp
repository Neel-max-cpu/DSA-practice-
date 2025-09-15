class Solution {
public:
    int findDuplicate(vector<int>& arr) {
        // int i = 0;
        // int curr = -1;
        // while(true){
        //     if(arr[i]==-1) return curr;
        //     curr = arr[i];            
        //     arr[i] = -1;
        //     i = curr;
        // }
        // return -1;

        int fast = arr[0];
        int slow = arr[0];
        do{
            fast = arr[arr[fast]];
            slow = arr[slow];
        }
        while(slow!=fast);

        int newPointer = arr[0];
        while(slow!=newPointer){
            slow = arr[slow];
            newPointer = arr[newPointer];
        }
        return slow;
    }
};