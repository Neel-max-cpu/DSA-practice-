class MinStack {
public:
    // METHOD 1: -- with statck and pair o(1)
    stack<pair<int,int>>st;    

    // METHOD 2: -- with stack and encoding o(1)
    // stack<long>st;
    // long currMin;
    MinStack() { 
        // METHOD 2
        // currMin = LONG_MAX;       
    }
    
    void push(int value) {
        // METHOD 1:
        // /*
        int currMin;
        if(st.empty()) currMin = value;        
        else {
            int topMin = st.top().second;
            if(value<topMin) currMin = value;
            else currMin = topMin;
        }

        st.push({value, currMin});
        // */

        // METHOD 2:
        /*
        if(st.empty()){
            currMin = value;
            st.push(value);
            return;
        }

        if(value>currMin){
            st.push(value);
        }
        else{
            int newMin = value;
            long encode = 2*(long)newMin - currMin;
            st.push(encode);
            currMin = newMin;
        }
        */
    }
    
    void pop() {
        // METHOD 1 :
        st.pop();    

        // METHOD 2 :
        // long top = st.top();
        // st.pop();
        // if(top<currMin){
        //     int encoded = top;
        //     /*
        //     encoded = 2*newMin - oldMin
        //     oldMin = 2*newMin - encoded
        //     */
        //     long preMinElement = 2*currMin - encoded;
        //     currMin = preMinElement;
        // } 
        // if(st.empty()) currMin = LONG_MAX;
    }
    
    int top() {
        // METHOD 1:
        return st.top().first;

        // METHOD 2:
        // long top = st.top();
        // if(top>currMin) return (int) top;
        // else return (int) currMin;
    }
    
    int getMin() {
        // METHOD 1:
        return st.top().second;

        // METHOD 2:
        // return (int) currMin;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */