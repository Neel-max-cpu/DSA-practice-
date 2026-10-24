class Solution {
public:
    int helper(string aa, string la, string ab, string lb){
        unordered_map<string,int>m;
        m["01"] = 31;
        m["02"] = 28;
        m["03"] = 31;
        m["04"] = 30;
        m["05"] = 31;
        m["06"] = 30;
        m["07"] = 31;
        m["08"] = 31;
        m["09"] = 30;
        m["10"] = 31;
        m["11"] = 30;
        m["12"] = 31;       

        string monthAliceArrive = aa.substr(0,2); 
        string monthAliceLeave = la.substr(0,2);
        string monthBobArrive = ab.substr(0,2);
        string monthBobLeave = lb.substr(0,2);  
        cout<<monthAliceArrive<<" "<<monthAliceLeave<<" "<<monthBobArrive<<" "<<monthBobLeave<<endl;

        string dayAliceArrive = aa.substr(3,2); 
        string dayAliceLeave = la.substr(3,2);
        string dayBobArrive = ab.substr(3,2);
        string dayBobLeave = lb.substr(3,2);        
        cout<<dayAliceArrive<<" "<<dayAliceLeave<<" "<<dayBobArrive<<" "<<dayBobLeave<<endl;

        string aliceArrive = monthAliceArrive+dayAliceArrive;
        string aliceLeave = monthAliceLeave+dayAliceLeave;
        string bobArrive = monthBobArrive+dayBobArrive;
        string bobLeave = monthBobLeave+dayBobLeave;
        cout<<aliceArrive<<" "<<aliceLeave<<" "<<bobArrive<<" "<<bobLeave<<endl;

        // alice leave < bob arrive || alice arrive > bob leave
        if(stoi(aliceLeave) < stoi(bobArrive) || stoi(aliceArrive) > stoi(bobLeave)) return 0;

        string commonArrive = max(aliceArrive, bobArrive);
        string commonLeave = min(aliceLeave, bobLeave);
        cout<<commonArrive<<" "<<commonLeave<<endl;
        int ans = 0;
        // check if in same month
        if(commonArrive.substr(0,2) == commonLeave.substr(0,2)){
            // add the days+1(including )
            int days = stoi(commonLeave.substr(2,2)) - stoi(commonArrive.substr(2,2));
            ans = days+1;
        }       
        else{
            // month is different
            int days = 0;
            int diff = stoi(commonLeave.substr(0,2)) - stoi(commonArrive.substr(0,2));
            
            // total days
            int monthDays = m[commonArrive.substr(0,2)];
            int usedDays = stoi(commonArrive.substr(2,2));
            int leftDays = monthDays - usedDays;
            days+=leftDays;            
            
            if(diff>1){
                // excluding the arrive month and leave month add the days
                string start = commonArrive.substr(0,2);
                string end = commonLeave.substr(0,2);

                int s = stoi(start);
                int e = stoi(end);

                for(int i=s+1; i<e; i++){
                    string temp = (i < 10 ? "0" : "") + to_string(i);
                    days+=m[temp];
                }
            }

            // add the remaining days from leave
            days+=stoi(commonLeave.substr(2,2));

            // including 
            ans = days+1;
        }
        
        return ans;
    }

    int countDaysTogether(string aa, string la, string ab, string lb) {
        
        // mine --- 
        // return helper(aa, la, ab, lb);   

        //both are optimal just this is more readable--
        vector<int> days = {
            31, 28, 31, 30, 31, 30,
            31, 31, 30, 31, 30, 31
        };

        auto getDay = [&](string date) {
            int month = stoi(date.substr(0, 2));
            int day = stoi(date.substr(3, 2));

            // except the current month add all previous months
            for (int i = 0; i < month - 1; i++) {
                day += days[i];
            }

            return day;
        };

        /* convert the entire month-day to days eg 
        "08-15"(15th aug in days is 227) - alice arrive
        "08-18"(1th aug in days is 230) - alice leave
        "08-16"(1th aug in days is 228) - bob arrive 
        "08-19"(1th aug in days is 231) - bob leave
        */
        int aliceStart = getDay(aa);
        int aliceEnd = getDay(la);
        int bobStart = getDay(ab);
        int bobEnd = getDay(lb);

        // cout<<aliceStart<<" "<<aliceEnd<<" "<<bobStart<<" "<<bobEnd<<endl;

        int start = max(aliceStart, bobStart);
        int end = min(aliceEnd, bobEnd);
        // if no over lap end-start+1 will result in -ve so max of 0 and overlap
        // cout<<end-start+1<<endl;

        return max(0, end - start + 1);


    }
};