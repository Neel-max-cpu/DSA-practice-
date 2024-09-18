class KthLargest {
public:
    priority_queue<int>maxHeap;
    priority_queue<int, vector<int>, greater<int>>minHeap;
    KthLargest(int k, vector<int>& nums) {
        for(auto it:nums){
            minHeap.push(it);
        }
        // minHeap(nums.begin(), nums.end());
        int temp = k-1;
        while(minHeap.size()!=temp){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        maxHeap.push(minHeap.top());
        minHeap.pop();
        return maxHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */