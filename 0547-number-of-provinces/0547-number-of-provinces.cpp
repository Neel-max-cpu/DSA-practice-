class Solution {
public:

    void helper(vector<vector<int>>&arr, int n, int start, vector<bool>&visited){
        visited[start] = true;
        for(int i=0; i<n; i++){
            if(arr[start][i]==1 && !visited[i])
                helper(arr, n, i, visited);
        }
    }

    int doFind(vector<int>&parent, int n){
        int p = parent[n];
        while(p!=parent[p]){
            parent[p] = parent[parent[p]];
            p = parent[p];
        }
        return p;
    }


    int doUnion(vector<int>&parent, vector<int>&rank, int a, int b){
        int p1 = doFind(parent, a);
        int p2 = doFind(parent, b);
        if(p1 == p2) return 0;
        if(rank[p1]>rank[p2]){
            parent[p2] = p1;
            rank[p1]+=rank[p2];
        }
        else{
            parent[p1] = p2;
            rank[p2]+=rank[p1];
        }
        return 1;
    }

    int findCircleNum(vector<vector<int>>& arr) {
        // similar to connected component in Graph - a2z sheet graph lec1:learning  4th Q
        int n = arr.size();
  
        // using dfs can be done by bfs too
        /*
        vector<bool>visited(n, false);
        int count = 0;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                count++;
                helper(arr, n, i, visited);
            }
        }
        return count;
        */

        // using union find --
        vector<int>parent;
        vector<int>rank;
        for(int i=0; i<n; i++){
            parent.push_back(i);
            rank.push_back(i);
        }   

        int result = n;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                // 0 means not connected and a node is itself 
                if(i==j || arr[i][j]==0) continue;
                else if(arr[i][j]==1){
                    int a = i;
                    int b = j;
                    result -= doUnion(parent, rank, a, b);
                }
            }
        }
        return result;


    }
};