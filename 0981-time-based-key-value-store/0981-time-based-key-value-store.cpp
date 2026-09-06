class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>>m;
    TimeMap() {        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto& arr = m[key];
        string ans = "";

        // method 1--
        // since strictly increeasing time stamp so it works --
        /*
        if(arr.empty()) return ans;        

        int left = 0, right = arr.size()-1;
        while(left<=right){
            int mid = left + (right-left)/2;
            if(arr[mid].first == timestamp){
                ans = arr[mid].second;
                return ans;
            }
            else if(arr[mid].first<timestamp){
                // could be the ans - go higher
                ans= arr[mid].second;
                left = mid+1;
            }
            else{
                // go lower
                right = mid-1;
            }
        }
        return ans;
        */

        // method 2 --  
        // same binary search but using upper bound -- last element ≤ timestamp
        // why upper bound since > than query so return upper bound - 1
        // lower bound >= so extra checks        
        auto it = upper_bound(arr.begin(), arr.end(), timestamp, compare);
        if(it!=arr.begin()){
            it--;
            return it->second;
        }
        else return "";     
    }

    static bool compare(int time, const pair<int,string>&p){
        return time<p.first;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */