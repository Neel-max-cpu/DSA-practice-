class Solution {
public:

    void helper(vector<int>&a, int target, vector<vector<int>>&ans, vector<int>&ds, int i){
        // base case
        if(i==a.size()){
            if(target==0){
                ans.push_back(ds);
            }
            return;
        }

        if(a[i]<=target){
            ds.push_back(a[i]);
            helper(a, target-a[i], ans, ds, i);
            ds.pop_back();
        }
        helper(a, target, ans, ds, i+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        helper(candidates, target, ans, ds, 0);
        return ans;
    }
};