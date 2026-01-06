class MyStack {
public:
    // using deque M1
    // deque<int>dq;

    // using 2 queue - keep q1 as main and q2 as temp
    queue<int>q1;
    queue<int>q2;
    MyStack() {
    }
    
    void push(int x) {
        // dq.push_back(x);

        q2.push(x);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1,q2);
    }
    
    int pop() {
        /*
        int x= dq.back();
        dq.pop_back();
        return x;
        */

        int ans = -1;
        ans = q1.front();
        q1.pop();
        return ans;
    }
    
    int top() {
        // return dq.back();

        if(q1.empty()) return -1;
        else return q1.front();
    }
    
    bool empty() {
        // return dq.empty();

        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */