
#include <vector>
#include <algorithm>
#include <set>

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        int n = arr.size();
        // brute o(n3)
        /*
        set<vector<int>>st;
        for(int i=0;i<n; i++){
            for(int j=i+1; j<n; j++){
                for(int k=j+1; k<n; k++){
                    int sum = arr[i] + arr[j] + arr[k];
                    if(sum == 0) {
                        vector<int>temp = {arr[i], arr[j], arr[k]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);                    
                    }
                }
            }
        }
        vector<vector<int>>ans(st.begin(), st.end());
        return ans;
        */

        // better brute o(n2)
        /*
        set<vector<int>>st;
        for(int i=0;i<n; i++){
            set<int>hashset;
            for(int j=i+1; j<n; j++){
                int third = -(arr[i]+arr[j]);
                if(hashset.find(third) != hashset.end()){
                    vector<int>temp = {arr[i], arr[j], third};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hashset.insert(arr[j]);
            }
        }
        vector<vector<int>>ans(st.begin(), st.end());
        return ans;
        */

        // best -- o(nlogn) + o(n2)
        vector<vector<int>>ans;
        sort(arr.begin(), arr.end());
        for(int i=0;i<n; i++){
            if(i>0 &&  arr[i] == arr[i-1]) continue;

            int j = i+1, k = n-1;
            while(j<k){
                int sum = arr[i] + arr[j] + arr[k];
                if(sum==0){
                    vector<int>temp = {arr[i], arr[j], arr[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    while(j<k && arr[j]==arr[j-1]) j++;
                    while(j<k && arr[k]==arr[k+1]) k--;
                }
                else if(sum<0){
                    // increase
                    j++;
                }
                else {
                    // decrease
                    k--;
                }
            }
        }
        return ans;
    }
};