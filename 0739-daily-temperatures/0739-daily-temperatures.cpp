class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        int n = arr.size();
        vector<int>ans(n,0);

        // good --
        /*
        stack<pair<int,int>>st;
        for(int i=0; i<n; i++){                                        
            while(!st.empty() && st.top().first<arr[i]){
                auto x = st.top();
                st.pop();
                int index = x.second;
                int days = i-index;
                ans[index] = days;
            }
            st.push({arr[i], i});             
        }
        return ans;
        */

        // little better -- not storing the temp again
        stack<int>st;
        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()]<arr[i]){
                int index = st.top();
                st.pop();
                int days = i-index;
                ans[index]=days;
            }
            st.push(i);
        }
        return ans;

    }
};