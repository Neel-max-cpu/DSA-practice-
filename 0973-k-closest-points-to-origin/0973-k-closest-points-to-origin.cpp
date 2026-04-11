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
    }
};