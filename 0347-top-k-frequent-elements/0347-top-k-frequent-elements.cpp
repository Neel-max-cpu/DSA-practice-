class Neel{
    public: 
    int val; int freq;
};

struct compare{
    bool operator()(const Neel &x, Neel &y ){
        // x.freq>y.freq;
        // x's freq greater than y's freq so y has lower priority values so comes out first
        // so opposite        
        return x.freq<y.freq;
    }
};

class Solution {
public:    
    vector<int> topKFrequent(vector<int>& arr, int k) {
        unordered_map<int,int>m;
        for(auto it:arr){
            m[it]++;
        }

        priority_queue<Neel, vector<Neel>, compare>pq;
        for(auto it:m){
            pq.push({it.first, it.second});
        }

        vector<int>ans;
        while(k>0){
            Neel x = pq.top();
            pq.pop();
            ans.push_back(x.val);
            k--;
        }
        return ans;
    }
};