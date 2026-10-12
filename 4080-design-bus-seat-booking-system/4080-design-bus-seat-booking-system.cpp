class BusBooking {
public:
    vector<vector<pair<int,int>>>bus;
    int totalTime;
    int totalBooked;
    BusBooking(int n) {    
        bus.assign(n, vector<pair<int, int>>(4, {-1, 0}));
        totalTime = 0;
        totalBooked = 0;
    }
    
    void toggle(string seat) {
        string x = seat.substr(1);        
        int row = stoi(x);        
        row--;
        char c = seat[0];
        int col;
        // not window - b,c
        if(c=='B' || c=='C') {            
            if(c=='B'){
                col = 1;    
            }
            if(c=='C'){
                col = 2;    
            }
            // not visited
            if(bus[row][col].first ==-1) {
                bus[row][col] = {1,0};
                totalTime++;
                totalBooked++;
            }
            else{
                // visited
                bus[row][col] = {-1,0};
                totalTime--;
                totalBooked--;                
            }
        }
        // window seat
        else{
            if(c=='A'){
                col = 0;    
            }
            if(c=='D'){
                col = 3;    
            }

            // not visited
            if(bus[row][col].first==-1) {
                bool extra = false;
                if(col==0){
                    extra = bus[row][col+1].first == 1 ? true:false;
                }
                else if(col==3){
                    extra = bus[row][col-1].first == 1 ? true:false;                    
                }       
                
                if (extra) {
                    totalTime += 3;
                    bus[row][col] = {1, 1};
                }
                else {
                    totalTime++;
                    bus[row][col] = {1, 0};
                }

                totalBooked++;
            }
            else{
                // visited

                // Already booked: free it.
                // Subtract the ORIGINAL booking cost.
                if (bus[row][col].second == 1) {
                    totalTime -= 3;
                }
                else {
                    totalTime--;
                }

                bus[row][col] = {-1, 0};
                totalBooked--;
            }
        }
    }
    
    int getTotalTime() {
        return totalTime;
    }
    
    int getMinTime() {
        return totalBooked;
    }
};

/**
 * Your BusBooking object will be instantiated and called as such:
 * BusBooking* obj = new BusBooking(n);
 * obj->toggle(seat);
 * int param_2 = obj->getTotalTime();
 * int param_3 = obj->getMinTime();
 */