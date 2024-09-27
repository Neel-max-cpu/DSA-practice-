class Solution {
public:
    bool bfs(int start, vector<int>&color, vector<vector<int>>&graph){
        color[start] = 0;
        queue<int>q;
        q.push(start);
        while(!q.empty()){
            int front = q.front();
            q.pop();

            for(auto it:graph[front]){                
                if(color[it]==-1) {
                    color[it] = !color[front]; 
                    q.push(it);
                }
                else if(color[it]==color[front]) return false;
            }
        }
        return true;
    }

    bool dfs(int start, int col, vector<int>&color, vector<vector<int>>&graph){        
        color[start] = col;
        for(auto it:graph[start]){
            if(color[it]==-1){                                               
                if(!dfs(it, !col, color, graph)) return false;
            }
            else if(color[it]==color[start]) return false;
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        // linear can have bipartie, cycle graph with even node can have , but odd one can't
        int v = graph.size();

        // using bfs/dfs --
        vector<int>color(v, -1);        
        for(int i=0; i<v; i++){
            if(color[i]==-1) {
                // if(!bfs(i, color, graph)) return false;                
                if(!dfs(i, 0, color, graph)) return false;
            }
        }
        return true;
       
    }
};