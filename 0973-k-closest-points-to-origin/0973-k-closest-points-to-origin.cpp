struct Neel{
    double val;
    int row;
};

struct comp{
    bool operator()(Neel *a, Neel *b){
        return a->val>b->val;
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        /*
        priority_queue<Neel*, vector<Neel*>, comp>minHeap;
        for(int i=0; i<points.size(); i++){
            int first = points[i][0];
            int second = points[i][1];

            double val = first*first + second*second;
            val = (double) sqrt(val);

            Neel *newNode = new Neel();
            newNode->val = val;
            newNode->row = i;
            minHeap.push(newNode);
        }        
     
        vector<vector<int>>ans;        
        while(!minHeap.empty()){
            if(k==0) break;
            auto x = minHeap.top();
            minHeap.pop();
            k--;
            int first = points[x->row][0];
            int second = points[x->row][1];
            ans.push_back({first, second});
        }
        return ans;
        */

        // little better -- don't need sqroot
        /*
        auto comp = [](const vector<int>& a, const vector<int>& b) {
            return a[0]*a[0] + a[1]*a[1] > b[0]*b[0] + b[1]*b[1];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)>minHeap(comp);

        for(auto it:points){
            minHeap.push({it[0], it[1]});
        }
        vector<vector<int>>ans;
        for(int i=0; i<k; i++){
            ans.push_back(minHeap.top());
            minHeap.pop();
        }
        return ans;
        */
        
        // optimal -- using maxheap (only keep k eles) remove the maxHeap.top() -- will give the furthest
        priority_queue<pair<int, pair<int,int>>> maxHeap;

        for(auto it:points){
            int dist = it[0]*it[0] + it[1]*it[1];
            maxHeap.push({dist, {it[0], it[1]}});
            if(maxHeap.size()>k) maxHeap.pop();
        }

        vector<vector<int>>ans;
        while(!maxHeap.empty()){
            ans.push_back({maxHeap.top().second.first,maxHeap.top().second.second});
            maxHeap.pop();
        }
        return ans;
    }
};