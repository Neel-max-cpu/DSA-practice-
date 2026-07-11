class Solution {
public:
    vector<vector<int>> createAdj(int v, vector<vector<int>>&arr){
        vector<vector<int>>adj(v);
        for(int i = 0; i<arr.size(); i++){
            int first = arr[i][0];
            int second = arr[i][1];
            // directed            
            adj[second].push_back(first);
        }
        return adj;
    }        


    bool dfsCycle(int node, vector<vector<int>>&adj, vector<bool>&visited, vector<bool>&pathVisited){
        visited[node] = true;
        // its in the same path
        pathVisited[node] = true;

        for(auto it:adj[node]){
            if(!visited[it]){
                bool flag = dfsCycle(it, adj, visited, pathVisited);
                // if true then cycle
                if(flag) return true;
            }
            // if already visted 
            else{
                // then check for pathVisited (same path)
                if(pathVisited[it]) return true;
                else continue;
            }
        }

        // remove it since returned
        pathVisited[node] = false;
        return false;
    }

    bool dfs(vector<vector<int>>&adj, int v){
        vector<bool>visited(v, false);
        vector<bool>pathVisited(v, false);

        for(int i=0; i<v; i++){
            if(!visited[i]){
                bool flag = dfsCycle(i, adj, visited, pathVisited);
                if(flag){
                    // has cycle so cant finish course
                    return false;
                }
            }
        }
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // directed graph
        vector<vector<int>>adj = createAdj(numCourses, prerequisites);   

        // dfs
        return dfs(adj, numCourses);
    }
};