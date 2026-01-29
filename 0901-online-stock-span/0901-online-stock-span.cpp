class StockSpanner {
public:
    // brute ---
    // vector<int>v;    

    //optimal ---
    stack<pair<int,int>>st;
    int idx;
    StockSpanner() {        
        idx = 0;
    }
    
    int next(int price) {
        // brute
        /*
        v.push_back(price);
        int span = findSpan(v);
        return span;
        */
      
        while(!st.empty() && st.top().first<=price){
            // while the top ele is <= price pop -- since we need to keep the stack in decreasing order
            st.pop();
        }
        int span = 0;
        if(st.empty()){
            // basically idx - (-1) considering empty = -1 (eg at 0 st is empty idx 0 - (-1) = 1ele)
            span = idx+1;            
        }
        else{
            // not right - left+1 since we don't include the top ele(since we need) <=
            span = idx-st.top().second;             
        }    
        st.push({price, idx});
        idx++;
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