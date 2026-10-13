class Solution {
public:
    long long maxAlternatingSum(vector<int>& arr) {
        int n = arr.size();
        vector<long long>v;
        for(auto it:arr){
            long long data = (long long)it * (long long)it;
            v.push_back(data);
        }
        sort(v.begin(), v.end(),greater<long long>());                    

        long long ans = 0;
        for(int i=0; i<n/2; i++){            
            long long val1 = v[i];
            long long val2 = v[n-1-i];            
            ans += val1-val2;
        }
        if(n%2==1)
            ans = ans + v[n/2];
        return ans;
    }   
};