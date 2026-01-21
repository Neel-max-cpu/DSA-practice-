class MinStack {
public:
    stack<int>st;
    priority_queue<int,vector<int>,greater<int>> pq;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        pq.push(val);
    }
    
    void pop() {
        int x = st.top();
        popQ(x);
        st.pop();
    }
    
    int top() {
        if(st.empty()) return -1;
        else return st.top();
    }
    
    int getMin() {
        if(pq.empty()) return -1;
        else return pq.top();
    }

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
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */