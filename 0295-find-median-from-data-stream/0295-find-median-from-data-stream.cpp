class MedianFinder {
public:
    // maxHeap
    /*
    Contains the smaller half of numbers
    Top = largest of the smaller half
    */
    priority_queue<int>left;
    
    // min heap 
    /*
    Contains the larger half of numbers
    Top = smallest of the larger half
    */
    priority_queue<int, vector<int>, greater<int>> right;

    // keep the size diff 1
    int size;
    MedianFinder() {
        size = 0;
    }

    void reArrange(int n, int m){
        // move the top element from bigger size heap to smaller size heap
        if(n>m){
            //left has more ele move to right
            int x = left.top();
            left.pop();
            right.push(x);
        }
        else{
            int x = right.top();
            right.pop();
            left.push(x);
        }
    }
    
    void addNum(int num) {
        size++;
        if(left.empty()){
            left.push(num);
        }
        else{
            int leftTop = left.top();                        
            if(num<=leftTop){
                left.push(num);
            }
            else right.push(num);            
        }

        //check size diff
        int n = left.size();
        int m = right.size();
        if(abs(n-m)>1){
            reArrange(n,m);
        }
    }
    
    double findMedian() {
        int n = left.size();
        int m = right.size();
        if(size%2==1){
            if(n>m) return double (left.top());
            else return double (right.top());
        }
        else{
            double ans = (left.top()+right.top())/2.0;
            return ans;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */