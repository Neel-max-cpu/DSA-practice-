class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        for(auto it:nums){
            m[it]++;
        }

        priority_queue<pair<int,int>>pq;
        for(auto it:m){
            pq.push({it.second, it.first});
        }

        vector<int>ans;
        while(k>0 && !pq.empty()){
            k--;
            auto x = pq.top();
            ans.push_back(x.second);
            pq.pop();
        }
        return ans;
    }
};