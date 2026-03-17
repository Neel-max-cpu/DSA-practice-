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
    int helper(TreeNode*root, int &ans){
        if(root==NULL) return INT_MIN;

        int left = helper(root->left, ans);
        int right = helper(root->right, ans);

        int one = root->val;
        int two = root->val;
        int three = root->val;
        int four = root->val;
        if(left!=INT_MIN)
            two += left;
        if(right!=INT_MIN)
            three += right;
        if(left!=INT_MIN && right!=INT_MIN)
            four += left + right;

        // we can send root, root+down left or root+down right
        int res = max({one, two, three});
        // global max could be ans, res(3 options), or max that node(four)
        ans = max({ans, res, four});
        return res;
    }

    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        helper(root, ans);
        return ans;
    }
};