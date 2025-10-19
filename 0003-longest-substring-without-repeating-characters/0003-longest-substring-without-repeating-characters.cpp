class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l = 0, r=0;
        int len = 0;
        unordered_set<char>st;

        //better approach o(2n worst case l also have to traverse the entire array with r so n+n)
        /*
        while(r<n){
            char x = s[r];
            if(st.find(x)!=st.end()){
                //if found l,r range has repeating character
                while(st.find(x)!=st.end()){
                    //check if x is present in the set or not 
                    // - yes then = remove the element from the set and l++, and repeat until x is removed
                    st.erase(s[l]);
                    l++;
                }
                // once done check len
                len = max(len, r-l+1);
                // then again insert x now then r++ 
                st.insert(x);
                r++;
            }
            else{
                // not found l,r range has non repeating
                len = max(len, r-l+1);
                st.insert(x);
                r++;
            }
        }
        */
        //better --- o(2n)
        /*
        while(r<n){
            char x = s[r];

            //if duplicate found
            while(st.find(x)!=st.end()){
                st.erase(s[l]);
                l++;
            }
            st.insert(x);
            len = max(len, r-l+1);
            r++;
        }
        */

        //best o(n) - instead of traversing the l to r why not directly jump l to the req postion
        // so instead of taking a set we take a map with char and the last index it was found
        unordered_map<char,int>m;
        while(r<n){
            char x = s[r];
            //if duplicate found
            if(m.find(x)!=m.end()){
                // just go the next index of the last one -- also edge case l must always move forward
                /*
                s = "abba"
                r=0 → 'a' → m[a]=0, len=1
                r=1 → 'b' → m[b]=1, len=2
                r=2 → 'b' found → l jumps to 2 (m[b]+1)
                r=3 → 'a' found → l jumps to 1 (m[a]+1) ❌ but that’s backward!
                */
                // if last seen is less than l then no need to worry l is at correct pos
                int nextIndex = max(l,m[x]+1);  
                l = nextIndex;
                // we could erase the element from the map 
                // m.erase(x); -- but no need as its getting updated below,
                // and len is alos being calculated and r++ is being done
            }

            //not found put the value and index
            m[x] = r;
            len = max(len, r-l+1);
            r++;
        }

        return len;
        
    }
};