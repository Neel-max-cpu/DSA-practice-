class Solution {
public:
    vector<int> targetIndices(vector<int>& arr, int target) {
        sort(arr.begin(),arr.end());
        vector<int>ans;
        for(int i=0; i<arr.size(); i++){
            if(arr[i]==target){
                ans.push_back(i);
            }
        }
        return ans;
    }
};