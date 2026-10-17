class Solution {
public:
    int getSwaps1(vector<int>& arr) {
        // from gfg -- https://www.geeksforgeeks.org/problems/minimum-swaps/1
        int n = arr.size();
    
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++) {
            v.push_back({arr[i], i});
        }
        
        /* dry run -- [10, 19, 6, 3, 5]
        [(10,0), (19,1), (6,2), (3,3), (5,4)]
        sort - [(3,3), (5,4),(6,2), (10,0), (19,1)]
        
        swap = 0;
        visited - 0,0,0,0,0
        -- (i=0) visited - 1,0,0,1,0
        -- (i=1) visited - 1,1,0,1,1
        i: 0 (3,3)
        cycle = 0
        while->  
        j = 0: then j = 3; cycle = 1
        j = 3: then j = 0; cycle = 2
        j = 0: already visited break
        swap +=(0+) 2-1 = 1
        
        i: 1 (5,4)
        cycle = 0
        while->
        j = 1: then j = 4; cycle = 1
        j = 4: then j = 1; cycle = 2
        j = 1: already visited break
        swap +=(1+) 2-1 = 2
        
        i:2 (6,2) 2==2 continue
        
        i:3 (10,0) visited continue
        
        i:4 (19,1) visited continue
        
        */
    
        sort(v.begin(), v.end());
    
        vector<bool> visited(n, false);
        int swaps = 0;
    
        for (int i = 0; i < n; i++) {
            // if already visited or in correct position then continue
            if (visited[i] || v[i].second == i) {
                continue;
            }
    
            int cycleSize = 0;
            int j = i;
    
            while (!visited[j]) {
                visited[j] = true;
                j = v[j].second;
                cycleSize++;
            }
    
            if (cycleSize > 1) {
                swaps += cycleSize - 1;
            }
        }
    
        return swaps;
    }
    struct Node{
        int sum;
        int index;
        int value;
    };

    bool static compare(Node a, Node b){
        if (a.sum != b.sum)
            return a.sum < b.sum;      // Ascending order of sum

        return a.value < b.value;      // If sum is equal, ascending order of value
    }

    int getSum(int n){
        int sum = 0;
        while(n>0){
            sum+=n%10;
            n/=10;
        }
        return sum;
    }

    int getSwaps2(vector<Node>& v, int &n) {                   
        vector<bool> visited(n, false);
        int swaps = 0;
    
        for (int i = 0; i < n; i++) {
            // if already visited or in correct position then continue
            if (visited[i] || v[i].index == i) {
                continue;
            }
    
            int cycleSize = 0;
            int j = i;
    
            while (!visited[j]) {
                visited[j] = true;
                j = v[j].index;
                cycleSize++;
            }
    
            if (cycleSize > 1) {
                swaps += cycleSize - 1;
            }
        }
    
        return swaps;
    }


    int minSwaps(vector<int>& arr) {
        int n = arr.size();
        vector<Node>v;
        for(int i=0; i<n; i++){
            int sum = getSum(arr[i]);
            v.push_back({sum, i, arr[i]});
        }

        sort(v.begin(), v.end(), compare);

        // getSwaps1 is the original code from gfg 
        return getSwaps2(v, n);    
    }
};