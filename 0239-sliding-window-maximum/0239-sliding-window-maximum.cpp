class Solution {
public:

    int getMax(vector<int>&arr, int end, int k){
        int maxi = 0;
        int start = end - (k-1);
        for(int i=start; i<=end; i++){
            maxi = max(maxi, arr[i]);
        }
        return maxi;
    }
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        int n = arr.size();        
        vector<int>ans;

        // brute --
        /*
        for(int right=0; right<n; right++){
            if(right>=k-1){
                int currentMax = getMax(arr, right, k);
                ans.push_back(currentMax);
            }                                     
        }
        return ans;
        */        
        priority_queue<pair<int,int>>pq;  
        for(int right = 0; right<n; right++){
                     
            if(right>=k){
                // pop till the top is not in the current window or not --                
                // window from (right-k) to (right-1)
                while(!(pq.top().second>=right-k && pq.top().second<=right-1)){
                    pq.pop();
                }                
                auto x = pq.top();
                ans.push_back(x.first);
            }
            pq.push({arr[right], right});   

        }

        // for the last element        
        while(!(pq.top().second>=n-k && pq.top().second<=n-1)){
            pq.pop();
        }
        auto x = pq.top();
        ans.push_back(x.first);        

        return ans;
    }
};