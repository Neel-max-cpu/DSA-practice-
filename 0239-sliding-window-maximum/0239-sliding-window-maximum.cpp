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

        // brute -- o(nk)
        /*
        for(int right=0; right<n; right++){
            if(right>=k-1){
                int currentMax = getMax(arr, right, k);
                ans.push_back(currentMax);
            }                                     
        }
        return ans;
        */        

        // better -- o(nlogk)
        /*
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
        */

        // optimal --- 
        // max elemenet in the front and smaller in the back(descending order)
        // and if we get bigger element than we pop from the back and put it in place
        deque<int>dq;

        for(int i=0; i<n; i++){
            //case1:  if outside the window pop from front since oldest element there
            while(!dq.empty() && dq.front()+k-1 < i) dq.pop_front();

            // case2: curr is greater -- pop from back since newest element in back
            while(!dq.empty() && arr[i] >= arr[dq.back()]) dq.pop_back();

            dq.push_back(i);

            if(i>=k-1){
                ans.push_back(arr[dq.front()]);
            }
        }     

        return ans;
    }
};