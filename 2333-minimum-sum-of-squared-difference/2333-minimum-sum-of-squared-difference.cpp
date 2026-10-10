class Solution {
public:
    long long minSumSquareDiff(vector<int>& arr1, vector<int>& arr2, int k1, int k2) {         
        int n = arr1.size();
        int totalOperation = k1+k2;            
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
                long long reduce = totalOperation / groupSize;
                long long remainder = totalOperation % groupSize;
                for (int j = 0; j < groupSize; j++) {
                    long long val = currentLevel - reduce;

                    if (j < remainder) {
                        val--;
                    }

                    ans += val * val;
                }

                for (int j = i; j < n; j++) {
                    ans += 1LL * v[j] * v[j];
                }

                return ans;            
            }
        }

        long long ans = 0;
        long long reduce = totalOperation / groupSize;
        long long remainder = totalOperation % groupSize;
        for (int j = 0; j < groupSize; j++) {
            long long val = currentLevel - reduce;

            if (j < remainder) {
                val--;
            }

            ans += val * val;
        }

        return ans;
    }
};