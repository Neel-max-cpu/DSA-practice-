class Solution {
public:
    
    static bool custom(pair<int,int>&a, pair<int,int>&b){
        return a.second>b.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        for(int i=0; i<nums.size(); i++){
            m[nums[i]]++;
        }
        vector<pair<int,int>>p(m.begin(), m.end());
        
        sort(p.begin(), p.end(), custom);

        vector<int>ans(k);
        for(int i=0; i<k; i++){
            ans[i] = p[i].first;
        }
        return ans;
     
    }
};