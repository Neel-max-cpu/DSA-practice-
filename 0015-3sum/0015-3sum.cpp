class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        //brute - 3loopso(n^3)
        //better sort - 1 fixed then 2 sum(nlogn + n* (n-1 to 1 sum)~ n * log k - when inserting)
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<vector<int>>ans;
        for(int i=0; i<=n-3; i++){
            if(i>0 && arr[i]==arr[i-1]) continue;
            else{
                int j = i+1, k=n-1;
                while(j<k){

                    int sum = arr[i]+arr[j]+arr[k];
                    if(sum==0) {
                        ans.push_back({arr[i],arr[j], arr[k]});
                        j++;k--;
                        while(j<k && arr[j]==arr[j-1]) j++;
                        while(k>j && arr[k]==arr[k+1]) k--;                        
                    }
                    else if(sum>0){
                        k--;
                    }
                    else if(sum<0){
                        j++;
                    }
                }
            }
        }
        return ans;
    }
};