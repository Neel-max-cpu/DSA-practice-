class Solution {
public:
    int maxArea(vector<int>& arr) {
        int n = arr.size();
        int i = 0, j=n-1;
        int ans = 0;
        while(i<j){
            int height = min(arr[i], arr[j]);
            int len = j-i;
            int val = height*len;
            ans = max(ans, val);

            if(arr[i]>arr[j]) j--;
            else i++;
        }
        return ans;
    }
};