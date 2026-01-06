class MyQueue {
public:
    stack<int>s1;
    stack<int>s2;
    MyQueue() {
        
    }

    void putVal(vector<int>&v){
        for(int i=v.size()-1; i>=0; i--){
            s2.push(v[i]);
        }
    }
    void push(int x) {
        s2.push(x);
        vector<int>v;        
        while(!s1.empty()){            
            v.push_back(s1.top());
            s1.pop();
        }
        putVal(v);
        swap(s1,s2);
    }
    
    int pop() {
        if(empty()) return -1;
        int ans = s1.top();
        s1.pop();
        return ans;
    }
    
    int peek() {
        if(empty()) return -1;
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */