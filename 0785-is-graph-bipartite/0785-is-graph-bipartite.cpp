class Solution {
public:
    bool dfs(int node, int colr, vector<int>&color, vector<vector<int>>&adj){
        color[node] = colr;

        for(auto it:adj[node]){
            // if not colored
            if(color[it]==-1){          
                // put opposite color      
                bool flag = dfs(it, !colr, color, adj);
                if(!flag) return false;                
            }
            else if(color[it]==colr){
                // if adj has the same color
                return false;
            }                        
        }
        return true;
    }

    bool bfs(int node, vector<int>&color, vector<vector<int>>&adj){
        queue<int>q;
        q.push(node);
        color[node] = 0;

        while(!q.empty()){
            int currNode = q.front();
            q.pop();
            
            for(auto it:adj[currNode]){
                if(color[it]==-1){
                    // put opposite color                    
                    color[it]=!color[currNode];
                    q.push(it);
                }                
                else if(color[it]==color[currNode]) return false;                                 
            }
        }
        return true;        
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();        
        vector<int>color(v, -1);        

        for(int i=0; i<v; i++){
            if(color[i]==-1){
                // bool flag = dfs(i, 0, color, graph);
                bool flag = bfs(i, color, graph);
                if(!flag) return false;
            }
        }
        return true;
    }
};