class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l = 0, r=0;
        int len = 0;
        unordered_set<char>st;
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

        return len;
        
    }
};