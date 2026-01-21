class MinStack {
public:
    stack<int>st;
    
    // brute ---
    /*
    priority_queue<int,vector<int>,greater<int>> pq;
    */

    // better ---
    long minE;    
    stack<int>mini;
    MinStack() {
        // very large value
        minE = LONG_MAX;
    }
    
    void push(int val) {
        // brute ---
        /*        
        pq.push(val);
        */
        minE = min(minE, (long)val);            
        st.push(val);
        mini.push(minE);
    }
    
    void pop() {
        // brute ---
        /*
        int x = st.top();
        popQ(x);        
        */
        st.pop();
        mini.pop();
        if(mini.empty()) minE = LONG_MAX;        
        else{
            minE = mini.top();
        }
    }
    
    int top() {                
        if(st.empty()) return -1;
        else return st.top();           
    }
    
    int getMin() {
        // brute ---
        /*
        if(pq.empty()) return -1;
        else return pq.top();
        */
        if(mini.empty()) return -1;
        else return mini.top();
    }

    // brute ---
    /*
    private:
    void popQ(int x){
        vector<int>temp;
        while(pq.top()!=x){
            temp.push_back(pq.top());
            pq.pop();
        }

        // pop the ele
        pq.pop();

        for(auto it:temp) pq.push(it);
    }
    */
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */