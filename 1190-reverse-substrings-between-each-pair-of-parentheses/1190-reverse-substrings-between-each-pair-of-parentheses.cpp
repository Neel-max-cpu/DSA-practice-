class Solution {
public:
    string reverseParentheses(string s) {    
        int n = s.size();

        // o(n2) brute --
        /*
        stack<int>st;
        for(int i=0; i<n; i++){
            if(s[i]=='('){
                st.push(i);
            }
            else if(s[i]==')'){
                int start = st.top();
                st.pop();
                reverse(s.begin()+start+1, s.begin()+i);
            }
        }

        string ans = "";
        cout<<s<<endl;
        for(int i=0; i<n; i++){
            if(s[i]!='(' && s[i]!=')') ans+=s[i];
        }
        return ans;
        */

        /*
        (ed(et(oc))el) - oc to co
        (ed(et(co))el) - et(co) to )oc(te
        (ed()oc(te))el) - now the whole - ed()oc(te))el to le))et(co()de
        (le))et(co()de)
        */


        // optimized ---
        /*
        Find the matching ( for every ).
        Instead of reversing anything, jump between matching parentheses.
        Whenever you encounter a parenthesis, change the traversal direction.
        */
        vector<int>match(n);
        stack<int>st;
        for(int i=0; i<n; i++){
            if(s[i]=='(') st.push(i);
            else if(s[i]==')'){
                int start = st.top();
                st.pop();

                // reversed
                match[i] = start;
                match[start] = i;
            }
        }

        // for(int i=0; i<n ;i++){
        //     cout<<"i: "<<i<<" matching[i]: "<<match[i]<<endl;
        // }

        string ans;
        int i = 0;
        int direction = 1;
        while(i>=0 && i<n){
            if(s[i]=='(' || s[i]==')'){

                // cout<<"before i: "<<i<<" after i: ";
                i = match[i];
                // change direction
                direction = -direction;
                // cout<<i<<" direction:"<<direction<<endl;
            }
            else{
                ans+=s[i];
                // cout<<"i: "<<i<<" ans:"<<ans<<endl;
            }
            i+=direction;
        }
        return ans;

        /*  
        "(ed(et(oc))el)"
        0 1 2 3 4 5 6 7 8 9 10 11 12 13
        ( e d ( e t ( o c )  )  e  l  )

        matching pairs
        0 ↔ 13 (0,13),(13,0)
        3 ↔ 10 (3,10),(10,3)
        6 ↔ 9 (6,9),(9,6)
        match[0]  = 13
        match[13] = 0

        match[3]  = 10
        match[10] = 3

        match[6]  = 9
        match[9]  = 6

        for 
        i = 0; s[i]=(;  match[0] = 13; i = 13, direction = -1

        before i: 0 after i: 13 direction:-1
        i: 12 ans:l
        i: 11 ans:le
        before i: 10 after i: 3 direction:1
        i: 4 ans:lee
        i: 5 ans:leet
        before i: 6 after i: 9 direction:-1
        i: 8 ans:leetc
        i: 7 ans:leetco
        before i: 6 after i: 9 direction:1
        before i: 10 after i: 3 direction:-1
        i: 2 ans:leetcod
        i: 1 ans:leetcode
        before i: 0 after i: 13 direction:1

        0 → 13 (1 to -1)
        13 → 12 → 11 → 10      
        10 → 3 (-1 to 1)
        
        3 → 4 → 5 → 6 
        6 → 9 (1 to -1)

        9 → 8 → 7 → 6
        6 → 9 (again) (-1 to 1)

        9 → 10 
        10 → 3 (1 to -1)

        3 → 2 → 1 → 0 
        0 → 13 (-1 to 1)

        13 → 14(break > n)        
        */
    }
};




