class Solution {
public:
 void helper(vector<int>&arr, int i, int target, vector<vector<int>>&ans, vector<int>&temp){
        if(i==arr.size()){
            if(target==0){
                ans.push_back(temp);
            }
            return;
        }

        if(arr[i]<=target){
            temp.push_back(arr[i]);
            helper(arr, i, target-arr[i], ans, temp);
            temp.pop_back();
        }
        helper(arr, i+1, target, ans, temp);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
         vector<vector<int>>ans;
        vector<int>temp;
        helper(candidates, 0, target, ans, temp);
        return ans;
    }
};