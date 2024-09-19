class Solution {
public:

    void helper(vector<vector<int>>&arr, int n, int start, vector<bool>&visited){
        visited[start] = true;
        for(int i=0; i<n; i++){
            if(arr[start][i]==1 && !visited[i])
                helper(arr, n, i, visited);
        }
    }

    int findCircleNum(vector<vector<int>>& arr) {
        // similar to connected component in Graph - a2z sheet graph lec1:learning  4th Q
        int n = arr.size();
        vector<int>parent;
        vector<int>rank;
        for(int i=0; i<n; i++){
            parent.push_back(i);
            rank.push_back(i);
        }

        // using dfs can be done by bfs too
        vector<bool>visited(n, false);
        int count = 0;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                count++;
                helper(arr, n, i, visited);
            }
        }
        return count;
    }
};