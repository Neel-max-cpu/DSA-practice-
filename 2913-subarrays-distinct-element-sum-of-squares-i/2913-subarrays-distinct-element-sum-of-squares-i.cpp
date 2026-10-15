class Solution {
public:
    int sumCounts(vector<int>& arr) {
        int ans = 0;
        for(int i=0; i<arr.size(); i++){
            set<int>st;
            for(int j=i; j<arr.size();j++){
                st.insert(arr[j]);
                ans = ans + (st.size()*st.size());
            }
        }
        return ans;
    }
};