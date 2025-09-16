class Solution {
#define ll long long int
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        ll len = grid.size();
        ll n = len*len;
        ll sum = (n*(n+1))/2;
        ll sumSq = (n*(n+1)*(2*n+1))/6;

        ll actualSum = 0;
        ll actualSumSq = 0;
        for(auto it:grid){
            for(auto x:it){
                actualSum += x;
                actualSumSq += (x*x);
            }
        }

        ll diffSum = actualSum - sum;
        ll diffSumSq = actualSumSq - sumSq;

        ll x = diffSumSq/diffSum;
        ll y = diffSum;

        int repeating = (x+y)/2;
        int missing = (x-y)/2;
        return {repeating, missing};
    }
};