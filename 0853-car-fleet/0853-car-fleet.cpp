struct Neel{
    int one, two;
    float three;
};

class Solution {
public:
    static bool compare(Neel &a, Neel &b){
        return a.one>b.one;
    }

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<Neel>arr;
        for(int i=0; i<n; i++){
            float time = (target-position[i])/(float)speed[i];
            arr.push_back({position[i], speed[i], time});
                    
        }
        sort(arr.begin(), arr.end(), compare);

        float maxTime = arr[0].three;
        int fleet = 1;
        for(int i=1; i<n; i++){
            float time = arr[i].three;
            if(time > maxTime){
                maxTime = time;
                fleet++;
            }
        }
        return fleet;
    }
};