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
    int helper(TreeNode *root, bool &flag){
        if(root==NULL) return 0;

        int left = helper(root->left, flag);
        int right = helper(root->right, flag);
        if(flag == false){
            flag = false;
        }
        else{
            int diff = abs(left-right);
            if(diff>1){
                flag = false;
            }            
        }

        return 1+max(left, right);
    }

    int helper2(TreeNode*root){
        if(root==NULL) return 0;

        int left = helper2(root->left);
        int right = helper2(root->right);

        if(left==-1 || right == -1) return -1;
        
        int diff = abs(left-right);
        if(diff>1) return -1;
        else return 1+max(left, right);
    }

    bool isBalanced(TreeNode* root) {
        // true balanced/flag = unbalanced
        /*
        bool flag = true;
        helper(root, flag);
        return flag;
        */

        // optimal --
        int ans = helper2(root);
        return ans==-1? false : true;
    }
};