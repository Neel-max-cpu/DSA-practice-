class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        int currStock = arr[0];
        int profit = 0;
        for(int i=1; i<n; i++){
            profit = max(profit, arr[i]-currStock);
            if(currStock>arr[i]) currStock = arr[i];
        }
        return profit;
    }
};