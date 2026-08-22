class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        int n = arr.size();
        vector<vector<int>>ans;
        for(int i=0; i<=n-3; i++){
            if(i!=0 && arr[i]==arr[i-1]) continue;
            int j = i+1;
            int k = n-1;
            while(j<k){
                int sum = arr[i]+arr[j]+arr[k];
                if(sum==0){
                    ans.push_back({arr[i], arr[j], arr[k]});
                    k--; j++;
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
        return ans;
    }
};