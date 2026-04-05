/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode *helper(int left, int right, vector<int>&arr){
        if(left>right) return NULL;
        int mid = left + (right-left)/2;
        TreeNode*root = new TreeNode(arr[mid]);
        root->left = helper(left, mid-1, arr);
        root->right = helper(mid+1, right, arr);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();             
        TreeNode*root = helper(0, n-1, nums);
        return root;        
    }
};