class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        int n = arr.size();
        
        if(n==0) return 0;


        // kinda brute force --- time - o(n) + o(n*n = n2) and space = o(n)
        // or can go in a loop, and save x and do a linear search each time to find the next
        /*
        unordered_map<int,int>m;
        for(int i=0;i<n; i++) {
            m[arr[i]]++;
        }

        int ans = 0, count = 1;
        for(int i=0; i<n; i++){
            int x = arr[i];
            x++;
            while(m.find(x) != m.end()){
                count++;
                x++;
            }
            ans = max(ans, count);
            count = 1;
        }
        return ans;
        */

        // better sol
        // /*
        sort(arr.begin(), arr.end());
        int current = 0, last_smaller = INT_MIN;
        int count = 1;
        int ans = 0;
        for(int i=0; i<n; i++){
            current = arr[i];
            if(current==last_smaller+1){
                count++;
                last_smaller = current;
            }
            else if(current==last_smaller){
                continue;
            }
            else{
                ans = max(count, ans);
                last_smaller = current;
                count = 1;
            }
        }
        ans = max(count, ans);
        return ans;
        // */

        // best sol ------ similar to 1st one but we don't check for most of them
        /*
        unordered_set<int>s;
        for(int i=0; i<n; i++){
            s.insert(arr[i]);
        }

        int ans = 1;
        for(auto it:s){
            int x = it -1;
            if(s.find(x) != s.end()){
                // if we find the previous ele we continue, since we want to start from the 
                // first ele
                continue;
            }
            else{
                // may be the first ele so we start checking from here
                int count = 1;
                x = it+1;
                while(s.find(x)!=s.end()){
                    x++;
                    count++;
                }
                ans = max(ans, count);
                count = 1;
            }
        }
        return ans;
        */
    }
};