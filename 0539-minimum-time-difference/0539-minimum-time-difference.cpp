class Solution {
public:
    int findMinDifference(vector<string>& v) {
        int n = v.size();
        // brute ---
        /*
        int ans = INT_MAX;
        for(int i=0; i<n; i++){
            stringstream ss(v[i]);
            string str;            
            getline(ss, str, ':');
            int h1 = stoi(str);
            getline(ss, str, ':');
            int m1 = stoi(str);
            int total_min1 = h1*60+m1;       
            for(int j=i+1; j<n; j++){
                stringstream ss2(v[j]);
                string str2;                
                getline(ss2, str2, ':');
                int h2 = stoi(str2);
                getline(ss2, str2, ':');
                int m2 = stoi(str2);
                int total_min2 = h2*60+m2;
                if(total_min1 == 0 && total_min2==0) return 0;
                else{
                    int diff1 = abs(total_min1-total_min2);
                    // total min in a day 24*60 = 1440
                    int diff2 = 1440 - diff1;
                    ans = min({ans, diff1, diff2});
                }
            }
        }
        return ans;
        */

        vector<int>a;
        for(int i=0; i<n; i++){
            stringstream ss(v[i]);
            string s;
            getline(ss, s, ':');
            int hour = stoi(s);
            getline(ss, s, ':');
            int minutes = stoi(s);
            int total_min = hour*60+minutes;
            a.push_back(total_min);
        }
        sort(a.begin(), a.end());
        int ans = INT_MAX;
        for(int i=0; i<n; i++){
            int x = a[i];
            int y; 
            if(i==n-1) y = a[0];
            else y = a[i+1];

            if(x==0 && y==0) return 0;
            else{
                int diff1 = abs(x-y);
                // total min in a day 24*60 = 1440
                int diff2 = 1440-diff1;
                ans = min({ans, diff1, diff2});
            }
        }
        return ans;
    }
};