class Solution {
public:
    void helper(vector<int>&arr, int i, vector<int>&temp, vector<vector<int>>&ans){
        if(i==arr.size()){
            ans.push_back(temp);
            return;
        }

        //take the ele or skip
        temp.push_back(arr[i]);
        helper(arr, i+1, temp, ans);
        temp.pop_back();

        // skip
        helper(arr, i+1, temp, ans);

    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        helper(nums, 0, temp, ans);
        return ans;
    }
};