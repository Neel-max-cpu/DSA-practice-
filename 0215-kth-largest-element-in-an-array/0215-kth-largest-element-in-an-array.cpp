class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        /*                
        priority_queue<int>pq;
        for(auto it:nums){
            pq.push(it);            
        }          
        while(k>1){            
            pq.pop();
            k--;
        }
        return pq.top();
        */

        // since top is small so the smallest get discared and we are left with largest k elements in ascending order
        priority_queue<int, vector<int>, greater<int>>pq;
        for(auto it:nums){
            pq.push(it);            
            if(pq.size()>k) pq.pop();
        }
        return pq.top();
    }
};