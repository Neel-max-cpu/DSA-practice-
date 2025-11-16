class Solution {
public:

    void helper(vector<int>&nums, int n, vector<int>&ds, set<vector<int>>&ans, int idx){
        // base case
        if(idx == n){
            ans.insert(ds);
            return;
        }

        // pick the ele
        ds.push_back(nums[idx]);
        helper(nums, n, ds, ans, idx+1);
        ds.pop_back();

        // don't pick the ele
        helper(nums, n, ds, ans, idx+1);
    }

    void helper2(vector<int>&nums,int n, vector<int>&ds, vector<vector<int>>&ans, int idx){
        ans.push_back(ds);
        for(int i=idx; i<n; i++){
            if(i!=idx && nums[i]==nums[i-1]) continue;
            ds.push_back(nums[i]);
            helper2(nums, n, ds, ans, i+1);
            ds.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        // taking extra space and time --  set and time to convert set to vector
        /*
        vector<int>ds;
        set<vector<int>>ans;
        sort(nums.begin(), nums.end());
        helper(nums, n, ds, ans, 0);
        vector<vector<int>> res;
        res.insert(res.end(), ans.begin(), ans.end());
        return res;
        */

        vector<int>ds;
        vector<vector<int>>ans;
        sort(nums.begin(), nums.end());
        helper2(nums, n, ds, ans, 0);
        return ans;
    }
};