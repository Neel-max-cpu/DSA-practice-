class KthLargest {
public:
    int k;
    priority_queue<int,vector<int>, greater<int>>minHeap;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        // put all in minHeap - all in ascending order
        for(auto it:nums){
            minHeap.push(it);
            // keep only k eles
            if(minHeap.size()>k) minHeap.pop();
        }        

        /*
        push 4 → heap = [4]
        push 5 → heap = [4,5]
        push 8 → heap = [4,5,8]
        push 2 → heap = [2,4,5,8] → size > 3 → pop → remove 2
        so, final -- [4, 5, 8]
        */
    }
    
    int add(int val) {
        /*
        -- add 3
        Heap before: [4,5,8]
        push 3 → [3,4,5,8]
        size > 3 → pop → remove 3 now [4,5,8] return 4

        -- add 5 then [4,5,5,8] then pop 4 then [5,5,8] return 5
        -- add 10 then [5,5,8,10] then pop 5 then [5,8,10] return 5
        -- add 9 then [5,8,9,10] then pop 5 then [8,9,10] return 8
        -- add 4 then [4,8,9,10] then pop 4 then [8,9,10] return 8 
        */
        minHeap.push(val);
        if(minHeap.size()>k) minHeap.pop();
        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */