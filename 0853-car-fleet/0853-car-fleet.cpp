class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>>car;
        int n = position.size();
        for(int i=0; i<n; i++){
            car.push_back({position[i], speed[i]});
        }

        // sort by position--
        sort(car.begin(), car.end());

        double fleetAheadTime;
        int count=0;
        for(int i=n-1; i>=0; i--){
            // calculate time --
            int disLeft = target - car[i].first;
            int sp = car[i].second;

            double timeLeft = (double)disLeft/(double)sp;
            if(i==n-1) {
                count++;
                fleetAheadTime = timeLeft;
            }
            else{
                if(timeLeft > fleetAheadTime){
                    count++;
                    fleetAheadTime = timeLeft;
                }
                else{
                    // merge 
                }
            }
        }
        return count;        
    }
};