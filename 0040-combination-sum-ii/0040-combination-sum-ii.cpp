class Solution {
public:
    void helper(vector<int>&arr, int target, int idx, vector<vector<int>>&ans, vector<int>&temp){
        if(target==0){
            ans.push_back(temp);
            return;
        }

        for(int i=idx; i<arr.size(); i++){
            if(i!=idx && arr[i]==arr[i-1]) continue;
            if(arr[i]>target) break;
            temp.push_back(arr[i]);
            helper(arr, target-arr[i], i+1, ans, temp);
            temp.pop_back();
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        sort(candidates.begin(), candidates.end());
        helper(candidates, target, 0, ans, temp);
        return ans;
    }
};