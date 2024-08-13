class Solution {
public:

    void helper(vector<int>&a, int target, vector<int>&ds, set<vector<int>>&ans, int i){
        // base case
        if(i==a.size()){
            if(target==0){
                // ans.push_back(ds);
                ans.insert(ds);
            }
            return;
        }

        // pick the ele
        if(a[i]<=target){
            ds.push_back(a[i]);
            helper(a, target-a[i], ds, ans, i+1);
            ds.pop_back();
        }

        // dont pick the ele
        helper(a, target, ds, ans, i+1);
    }

    void helper2(vector<int>&a, int target, vector<int>&ds, vector<vector<int>>&ans, int idx){
        
        if(target==0) {
            ans.push_back(ds);
            return;
        }

        for(int i=idx; i<a.size(); i++){
            if(i!=idx && a[i]==a[i-1]) continue;
            // if(a[i]<=target){
            //     ds.push_back(a[i]);
            //     helper2(a, target-a[i], ds, ans, i+1);
            //     ds.pop_back();
            // }

            // or 
            if(a[i]>target) break;
            ds.push_back(a[i]);
            helper2(a, target-a[i], ds, ans, i+1);
            ds.pop_back();

        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        // using set tle --
        /*
        set<vector<int>>ans;
        vector<int>ds;
        sort(candidates.begin(), candidates.end());
        helper(candidates, target, ds, ans, 0);
        vector<vector<int>>res;
        res.insert(res.end(),ans.begin(), ans.end());
        return res; 
        */

        sort(candidates.begin(), candidates.end());
        vector<vector<int>>ans;
        vector<int>ds;
        helper2(candidates, target, ds, ans, 0);
        return ans;
    }
};