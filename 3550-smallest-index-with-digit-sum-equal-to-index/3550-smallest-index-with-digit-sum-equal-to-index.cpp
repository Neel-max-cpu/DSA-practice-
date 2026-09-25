class Solution {
public:
    bool check(int n, int i){
        int ans = 0;
        while(n>0){
            int x = n%10;
            ans+=x;
            n/=10;
        }
        return ans==i ? true : false;
    }

    int smallestIndex(vector<int>& arr) {
        int n = arr.size();
        int ans = -1;
        for(int i=0; i<n; i++){
            if(check(arr[i], i)){
                ans = i;
                break;
            }
        }
        return ans;
    }
};