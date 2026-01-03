class Solution {
public:
    vector<int> topKFrequent(vector<int>& arr, int k) {
        /*        
        unordered_map<int,int>m;
        for(auto it:arr){
            m[it]++;
        }

        priority_queue<pair<int,int>>pq;
        for(auto it:m){
            pq.push({it.second, it.first});
        }
        vector<int>ans;
        for(int i=0; i<k; i++){
            auto val = pq.top();
            pq.pop();
            ans.push_back(val.second);
        }
        return ans;
        */

        //follow up --
        unordered_map<int,int>m;
        for(auto it:arr){
            m[it]++;
        }
        int n = arr.size();
        vector<vector<int>>bucket(n+1);
        // at max if all the elems are equal - then ele will have n freq so n+1;
        for(auto it:m){
            // put the ele in their freq if 1 has 3freq then 3 -> 1
            //if 2 has 3 freq, then 3->1,2 ...
            bucket[it.second].push_back(it.first);
        }

        vector<int>ans;
        for(int i=n; i>=1 && ans.size()<k; i--){
            for(int it:bucket[i]){
                ans.push_back(it);
                if(ans.size()==k) break;
            }
        }
        return ans;
    }
};