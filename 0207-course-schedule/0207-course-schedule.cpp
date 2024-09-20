class Solution {
public:
    bool helper(int start, unordered_map<int,vector<int>>&m, unordered_set<int>&visited ){
        // already visited and course haven't ended
        if(visited.find(start)!=visited.end()) return false;
        
        if(m[start].empty()) return true;

        visited.insert(start);
        for(int i=0; i<m[start].size(); i++){
            int value = m[start][i];        
            if(!helper(value, m, visited)) return false;                                                            
        }

        // if course is completed erase all the prerequisites   
        m[start].clear();        
        // and mark as unvisited
        visited.erase(start);
        return true;
    }

    bool canFinish(int n, vector<vector<int>>& v) {
        unordered_map<int,vector<int>>m;
        for(int i=0; i<v.size(); i++){
            int a = v[i][0];
            int b = v[i][1];
            m[a].push_back(b);
        }
        
        // dfs from 0 to n-1
        unordered_set<int>visited;
        for(int i=0; i<n; i++){
            if(!helper(i, m, visited)) return false;
        }
        return true;
    }
};