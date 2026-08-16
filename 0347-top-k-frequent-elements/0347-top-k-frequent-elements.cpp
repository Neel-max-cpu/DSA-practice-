class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        for(auto it:nums){
            m[it]++;
        }

        vector<int>ans;
        /*
        priority_queue<pair<int,int>>pq;
        for(auto it:m){
            pq.push({it.second, it.first});
        }

        while(k>0 && !pq.empty()){
            k--;
            auto x = pq.top();
            ans.push_back(x.second);
            pq.pop();
        }
        return ans;
        */

        // best --
        int n = nums.size();
        vector<vector<int>>buckets(n+1);
        for(auto it:m){
            buckets[it.second].push_back(it.first);
        }

        for(int i=n; i>=1 && ans.size()<k; i--){
            for(auto it:buckets[i]){
                ans.push_back(it);
                if(ans.size()==k) break;
            }
        }
        return ans;
    }
};