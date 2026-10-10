class Solution {
public:
    long long minSumSquareDiff(vector<int>& arr1, vector<int>& arr2, int k1, int k2) {         
        int n = arr1.size();
        long long totalOperation = k1+k2;            
        vector<int>v;
        long long absSum = 0;
        for(int i=0; i<n; i++){
            int x = abs(arr1[i]-arr2[i]);
            int val = abs(arr1[i]-arr2[i]);
            v.push_back(val);
            absSum = absSum + x;
        }

        if(totalOperation>=absSum){
            return 0;
        }

        sort(v.begin(), v.end(), greater<int>());
        int currentLevel = v[0];
        int groupSize = 1;
        for(int i=1; i<v.size(); i++){
            /*
            eg - [8,8,8,5], now no need of k1, and k2 but think how many k1 and k2 
            would i need if i want to reduce all three 8s to 5 - where 8 current level and 5 next level? - sub 3 from all 8 then 3+3+3 = 9;
            - how? = there are 3 8s so group size = 3, current level = 8 and next level = 5
            (8-5)*3 = 3*3 = 9 operations
            */
            // (currentLevel - nextlevel) * groupSize
            long long cost = (currentLevel - v[i] )* (long long)groupSize;
            if(totalOperation >= cost){
                totalOperation -= cost;
                currentLevel = v[i];
                groupSize++;
            }
            else{
                // cant reach the next level
                long long ans = 0;
                // so need to reduce to certain elements in the group(could be the entire
                // group noOfElement = 0 or couple of abs elements, noOfElement > 0)
                long long valueToReduce = totalOperation / groupSize;
                long long noOfElement = totalOperation % groupSize;
                for (int j = 0; j < groupSize; j++) {
                    long long val = currentLevel - valueToReduce;
            
                    if (j < noOfElement) {
                        // subtract -1 too if the extra falls
                        val--;
                    }

                    // square the abs value too in a single loop
                    ans += val * val;
                }

                // square the remaing abs value in the array starting from i(next level)
                for (int j = i; j < n; j++) {
                    ans += 1LL * v[j] * v[j];
                }

                return ans;            
            }
        }


        // if we dont go to else and we did all the elements (here groupSize
        // will definately would be == n, and reset logic stays the same)
        long long ans = 0;
        long long valueToReduce = totalOperation / groupSize;
        long long noOfElement = totalOperation % groupSize;
        for (int j = 0; j < groupSize; j++) {
            long long val = currentLevel - valueToReduce;

            if (j < noOfElement) {
                val--;
            }

            ans += val * val;
        }

        return ans;
    }
};