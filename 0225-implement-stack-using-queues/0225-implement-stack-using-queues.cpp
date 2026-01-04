class MyStack {
public:
    queue<int>q1;
    queue<int>q2;
    // COMMENTED MY METHOD -- by alternating
    MyStack() {

    }
    
    void push(int x) {
        /*
        if(q1.empty()) {
            q1.push(x);
            while(!q2.empty()){
                q1.push(q2.front());
                q2.pop();
            }
        }
        else{
            q2.push(x);
            while(!q1.empty()){
                q2.push(q1.front());
                q1.pop();
            }
        }
        */

        // keep q1 as the main and q2 as temporary
        q2.push(x);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1,q2);
    }
    
    int pop() {
        /*
        int ans = -1;
        if(q1.empty()){
            ans = q2.front();
            q2.pop();
        }
        else{
            ans = q1.front();
            q1.pop();
        }
        return ans;
        */
        
        int ans = -1;
        ans = q1.front();
        q1.pop();
        return ans;
    }
    
    int top() {
        /*
        if(q1.empty()){
            return q2.front();
        }
        else return q1.front();
        */
        if(q1.empty()) return -1;
        else return q1.front();
    }
    
    bool empty() {
        /*
        if(q1.empty() && q2.empty()) return true;
        else return false;
        */

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