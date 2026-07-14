class Solution {
public:
    bool dfs(int node, vector<bool>&visited, vector<bool>&color, vector<vector<int>>&adj){
        visited[node] = true;

        for(auto it:adj[node]){
            if(!visited[it]){          
                // put opposite color      
                color[it]=!color[node];
                bool flag = dfs(it, visited, color, adj);
                if(!flag) return false;                
            }
            // already visited
            else{
                if(color[it]!=color[node]){
                    // opposite color
                    continue;
                }
                else{
                    // same color
                    return false;
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<bool>visited(v, false);
        vector<bool>color(v, false);        

        for(int i=0; i<v; i++){
            if(!visited[i]){
                bool flag = dfs(i, visited, color, graph);
                if(!flag) return false;
            }
        }
        return true;
    }
};