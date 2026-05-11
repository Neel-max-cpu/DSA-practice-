class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
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
    }
};