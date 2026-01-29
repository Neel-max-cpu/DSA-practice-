class StockSpanner {
public:
    vector<int>v;    
    StockSpanner() {        
    }
    
    int next(int price) {
        v.push_back(price);
        int span = findSpan(v);
        return span;
    }

    private:
    int findSpan(vector<int>&v){
        int n = v.size();
        if(n==0) return 0;
        int count = 1;
        int val = v[n-1];
        for(int i=n-2; i>=0; i--){
            if(v[i]<=val) count++;
            else return count;
        }
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */