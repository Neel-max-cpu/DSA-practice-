class Solution {
public:    
    stack<int>putAllInStack(vector<int>&arr){
        stack<int>st;
        for(auto it:arr) st.push(it);
        return st;
    }

    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;

        // brute --
        /*
        for(int i=0; i<n; i++){
            int mini = arr[i];
            for(int j=i; j>=0; j--){
                // curr area
                mini = min(mini, arr[j]);
                int currArea = mini*(i-j+1);
                ans = max(ans, currArea);
            }
        } 
        return ans;
        */

        // better - easier understanding than  best(same thing just here sc - o(3n) there o(n))        
        stack<int>st;
        // save index
        vector<int>smallLeft(n);
        vector<int>smallRight(n);
        
        // for left
        for(int i=0; i<n; i++){                        
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            // save index
            if(!st.empty()) smallLeft[i] = st.top();
            // if not available then can exted to the leftmost side (beyond 0th index)
            else smallLeft[i] = -1;

            st.push(i);            
        }

        // empty the stack - fastest why --assigning a new empty stack
        st = stack<int>();

        // for right
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            // save index
            if(!st.empty()) smallRight[i] = st.top();
            // if not available then can exted to the rightmost side (beyond n-1th index)
            else smallRight[i] = n;

            st.push(i);            
        }        
        for(int i=0; i<n; i++){
            /* from (smallLeft[i] + 1)  to  (smallRight[i] - 1) = (sR-1)-(sL+1)=sR-sL-1
            [since cant include the walls themselves - eg in [2,1,5,6,2,3] for wall 6
            sL=5(idx 2) and sR=2(idx 4) so (4-1)-(2+1)+1 = 3-3+1 = 1 = which is width 1]             
            */
            // caues minimun left size -1 and max right size n =             
            int width = smallRight[i]-smallLeft[i]-1;
            int area = arr[i]*width;
            ans = max(ans, area);
        }
        return ans;

        // best --- same as above but with one pass
        /*
        stack<int>st;
        // loop including the nth bar(doen't exist)
        for(int i=0; i<=n; i++){
            // current is smaller than the top or we reached then end(n)[if i==n we pop all and check]
            while(!st.empty() && (i==n || arr[st.top()]>=arr[i])){
                int height = arr[st.top()];
                st.pop();

                int width;
                if(st.empty()){
                    width = i;  // length can be whole basically (i-1)-0+1 = i
                }                
                else width = i-st.top()-1;
                int area = width*height;                
                ans = max(ans, area);
            }
            st.push(i);
        }              
        return ans;  
        */
        
        
    }
};