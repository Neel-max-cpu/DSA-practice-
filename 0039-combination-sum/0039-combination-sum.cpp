class Solution {
public:
    void recursion(vector<int>&arr, int target, int i, vector<vector<int>>&ans, vector<int>&temp, int sum){
        if(i==arr.size()){
            if(sum==target){
                ans.push_back(temp);
            }
            return;
        }
        if(sum==target){
            ans.push_back(temp);
            return;
        }
        if(sum>target) return;

        temp.push_back(arr[i]);
        recursion(arr, target, i, ans, temp, sum+arr[i]);
        temp.pop_back();
        recursion(arr, target, i+1, ans, temp, sum);
    }

    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        recursion(arr, target, 0, ans, temp , 0);
        return ans;
    }
};