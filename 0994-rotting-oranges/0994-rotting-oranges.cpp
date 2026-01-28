class Solution {
public:
    bool isValid(int i, int j, vector<vector<int>>&arr, int n, int m){
        if(i<0 || i>=n || j<0 || j>=m) return false;
        if(arr[i][j]==2 || arr[i][j]==0) return false;
        return true;
    }

    int orangesRotting(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();

        // put the initial rotten oranges here with row,col(arr[i][j] = 2)
        queue<pair<int,int>>q;
        int rotten = 0;
        int fresh = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m;j++){
                if(arr[i][j]==2){
                    q.push({i,j});
                    rotten++;
                }
                else if(arr[i][j]==1){
                    fresh++;
                }
            }
        }
        if(fresh==0) return 0;
        if(rotten==0 && fresh>0) return -1;
        if(rotten>=0 && fresh==0) return 0;

        // start level wise (bfs)
        int min = 0;
        queue<pair<int,int>>newQ;
        // cout<<"group min: "<<min<<" { ";
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            // can go 4 direction - left, right, up, down
            int dx[] = {-1,1,0,0};
            int dy[] = {0,0,-1,1};
            for(int i=0; i<4; i++){
                int newI = p.first+dy[i];
                int newJ = p.second+dx[i];
                if(isValid(newI, newJ, arr, n, m)){
                    // mark rotten
                    arr[newI][newJ] = 2;
                    // push
                    newQ.push({newI, newJ});
                    rotten++;
                    fresh--;
                }
            }
            // cout<<" ("<<p.first<<","<<p.second<<") ";            
            if(q.empty()){
                // cout<<" }"<<endl;                
                min++;
                if(fresh==0) return min;
                // cout<<"group min: "<<min<<" { ";
                q = newQ;
                // reset
                newQ = queue<pair<int,int>>();
            }
        }

        return fresh>0 ? -1:min;
    }
};