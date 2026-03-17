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
        // global max could be ans, res(best of 3 options), or max that node(four)
        // but in reality either one is correct root's val and (if left or right is valid then)
        // root'val + left/right and if both are valid then it will always be root's val+left+right
        ans = max({ans, res, four});
        return res;
    }

    int helper2(TreeNode *root, int&ans){
        if(root==NULL) return 0;

        int left = max(0, helper(root->left, ans));
        int right = max(0, helper(root->right , ans));

        // same here just better readability ----
        // global max could be ans, left could be 0 or val, right could be 0 or val, and root
        // in previous func -- ans = max of ans, res(worst case root's val - here same too if left,right = 0)
        // and root's val + left + right                
        ans = max(ans, left+right+root->val);

        //and i sent upward to parent either root, root+left, or root+right -- which is being handled in helper2
        //via max(left, right)+root->val so either left+root->val, right+root->val or 0+root->val
        return max(left, right)+root->val;
    }

    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        // helper(root, ans);
        helper2(root, ans);
        return ans;
    }
};