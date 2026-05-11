class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        /*
        vector<int>v(26,0);
        for(auto it:tasks){
            v[it-'A']++;
        }

        // default max heap most freq will be at the top
        priority_queue<int>maxHeap;
        for(auto it:v){
            if(it>0)
                maxHeap.push(it);
        }

        // to see when can i use the task again
        queue<pair<int,int>>q;

        int time = 0;
        while(!maxHeap.empty() || !q.empty()){        
            time++;

            if(maxHeap.empty()){
                time = q.front().second;
            } else{
                int freq = maxHeap.top();
                maxHeap.pop();
                freq--;
                if(freq>0){ 
                    int availableTime = time+n;
                    q.push({freq,availableTime});
                }
            }


            // check queue is non empty 
            if(!q.empty() && q.front().second==time){
                auto it = q.front();                
                maxHeap.push(it.first);
                q.pop();                                
            }
        }
        return time;
        */

        // more optimal -- but see the above one
        vector<int>v(26,0);
        for(auto it:tasks){
            v[it-'A']++;
        }

        sort(v.begin(), v.end());
        // max freq --
        int maxf = v[25];
        int idle = (maxf-1)*n;
        /*
          eg = A 4,B 1,C 1,D 1,G 1
          so maxf = 4 and n = 1 
          so idle = 3*1 = 3
          then A _ A _ A _ A - now need to fill them

          // arr -- 0,0,0,.....,1,1,1,1,4
          i = 24; idle = min(4-1, 1) = 3 - 1 = 2;
          i = 23; idle = min(4-1, 1) = 2 -1 = 1;
          i = 22; idle = min(4-1, 1) = 1 - 1 = 0;
        */

        for(int i=24; i>=0; i--){
            if(v[i]==0) break;
            idle -= min(maxf-1, v[i]);
        }
        return max(0, idle)+tasks.size();

    }
};