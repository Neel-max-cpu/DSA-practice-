class MedianFinder {
public:
    // method 1 --
    /*
    vector<int>v;
    int size;
    */

    // method 2 -- using max and min heap
    /* in max heap we will store half of the lower number -- so it will give
    max of smaller numbers
    in min heap we will store half of the greater number -- so it will give
    min of the larger number, so both's top will be the middle top element

    if even then maxheap size == min heap size
    else if odd then maxheap size == min heap size+1 (maxheap has 1 more ele)
    */

    // max heap
    priority_queue<int>maxHeap;
    // min heap
    priority_queue<int, vector<int>, greater<int>>minHeap;
    int k;

    MedianFinder() {
        // method 1 --
        /*
        size = 0;
        */
        k = 0;
    }
    
    void addNum(int num) {
        // method 1 --
        /*
        v.push_back(num);
        if(size!=0) 
            sort(v.begin(), v.end());
        size++;
        */

        k++;
        maxHeap.push(num);
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        if(minHeap.size()>maxHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        // method 1 --
        /*
        if(size%2==1) return v[size/2];
        else{
            double a = (double)(v[(size-1)/2] + v[size/2])/2.0;
            return a;
        }
        */
        if(k%2==1) return maxHeap.top();
        else {
            return (maxHeap.top()+minHeap.top())/2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */