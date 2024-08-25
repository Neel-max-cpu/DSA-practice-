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
    
    int diameter = 0;
    int findheight(TreeNode*root){
        if(root==NULL) return 0;
        
        int left = findheight(root->left);
        int right = findheight(root->right);        
        diameter = max(diameter, left+right);

        return max(left,right)+1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        // brute force
        findheight(root);
        return diameter;
    }
};