class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int>v;
        for(int i=0; i<queries.size(); i++){
            int first = queries[i][0];
            int second = queries[i][1];
            int x = 0;
            for(int i=first; i<=second; i++){
                int a = arr[i];                
                x^=a;
            }
            v.push_back(x);
        }
        return v;
    }
};