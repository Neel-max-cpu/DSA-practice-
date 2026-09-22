class FreqStack {
public:
    vector<vector<int>>freqBucket;    
    unordered_map<int,int>map;
    FreqStack() {        
    }
    
    void push(int val) {
        map[val]++;
        int freq = map[val];
        if(freqBucket.size()<freq){
            freqBucket.push_back({});
        }
        freqBucket[freq-1].push_back(val);    
        /*
        push(5)
        push(7)
        push(5)
        push(7)
        push(4)
        push(5)
        
        then --
        5 → 3
        7 → 2
        4 → 1

        in vector keeping it 0 base freq-1; so in each time i can pop back for latest
        frequency 2 → [5]
        frequency 1 → [7]
        frequency 0 → [5, 7, 4]
        */
    }
    
    int pop() {
        // max freq
        int n = freqBucket.size();
        int m = freqBucket[n-1].size();
        int val = freqBucket[n-1][m-1];
        freqBucket[n-1].pop_back();
        if(freqBucket[n-1].size()==0){
            freqBucket.erase(freqBucket.begin()+n-1);
        }
        map[val]--;
        if(map[val]==0) map.erase(val);
        return val;
        
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */