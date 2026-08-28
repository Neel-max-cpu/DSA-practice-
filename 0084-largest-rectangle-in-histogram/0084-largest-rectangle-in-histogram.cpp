class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        
        /*
        the question is not about how long i could stretch a historgam, its that is it viable to stretch
        eg -- 2,1,5,6,2,3

        i = 0, height = 2 and area = 2
        i = 1, height = 1 and current area = 1 (dont stretch i = 0 to 1 but try to stretch 1 to left or right) 

        if for any i at any point going left or right (j, k where j<i and i<k) value is smaller than i
        i.e arr[i]>arr[j] {where 0<=j<i} or arr[i]>arr[k] {where i<k<n} then break/cant go there
        -- best eg // brute -- o(n2) finding left/right take o(n2) -- try dryrunning
        */

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


        // brute -- o(n2) finding left/right take o(n2)
        /*
        // from i nearest smallest element in the left if not there then can go till end
        vector<int>left(n,-1);
        // from i nearest smallest element in the right if not there then can go till end
        vector<int>right(n,n);
        for(int i=0; i<n; i++){
            // for left
            int val = arr[i];
            for(int j=i-1; j>=0 ;j--){
                if(val>arr[j]) {
                    // have a smaller element so cant go left
                    left[i] = j;
                    break;
                }
            }
            // for right
            for(int j=i+1; j<n; j++){
                if(val>arr[j]){
                // have a smaller element so cant go right                
                    right[i] = j;
                    break;
                }
            }
        }

        // for(auto it:left){
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        // for(auto it:right){
        //     cout<<it<<" ";
        // }
        // cout<<endl;

        int ans = 0;
        for(int i=0; i<n; i++){
            int width = right[i]-left[i]-1;
            int area = arr[i]*width;
            ans = max(area, ans);
        }
        return ans;
        */
    
        // optimal -- finding the left/right using stack -- increasing height stack
        // /*
        vector<int>left(n,-1);
        vector<int>right(n,n);

        stack<int>st;
        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(!st.empty()) left[i] = st.top();
            else left[i] = -1;

            st.push(i);
        }

        st = stack<int>();
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            if(!st.empty()) right[i] = st.top();
            else right[i] = n;

            st.push(i);
        }

        int ans = 0;
        for(int i=0; i<n; i++){
            int width = right[i]-left[i]-1;
            int area = arr[i]*width;
            ans = max(ans, area);
        }
        return ans;
        // */

        // best single pass -- 9but see the above one its better understanding)
        // stack<int>st;
        // int ans = 0;
        // for(int i=0; i<=n; i++){
        //     while(!st.empty() && (i==n || arr[st.top()] >= arr[i])){
        //         // bar the stack top found its right boundary -- so compute area
        //         /* do dry run will understand but optimal is better --
        //         [2,1,5,6,2,3]
        //         i = 4; 6>=2 so right boundary of i=3(current stack top) is i-1(since arr[i]<=arr[stack top])
        //         and left boundary will be current stack.top() after pop 
        //         so width = (i - 1) - (st.top() + 1) + 1 = i-stack.top()-1
        //         if(stack.empty()) then width = i (since can extend till end - 0 to i-1 so total = i)
        //         then area = widht * arr[stack.top()]
        //         */

        //         int height = arr[st.top()];
        //         st.pop();
        //         int width = 0;
        //         if(st.empty()) width = i;
        //         else width = i-st.top()-1;
        //         int area = width * height;
        //         ans = max(ans, area);
        //     }
        //     st.push(i);
        // }
        // return ans;
    }
};