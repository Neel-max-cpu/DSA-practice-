class Solution {
public:

    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        int n = queries.size();
        vector<int>ans(n,-1);
        // min---
        // priority_queue <int, vector<int>, greater<int>> pq;

        // max --
        priority_queue <int> pq;
        int count = 1;
        for(int i=0; i<n; i++){
            int x = queries[i][0];
            int y = queries[i][1];
            int dist = abs(x)+abs(y);
            if(pq.size()<k){
                pq.push(dist);
            }
            else if(dist<pq.top()){
                pq.pop();
                pq.push(dist);
            }

            if(pq.size()==k)
                ans[i] = pq.top();
        }
        return ans;
    }
};