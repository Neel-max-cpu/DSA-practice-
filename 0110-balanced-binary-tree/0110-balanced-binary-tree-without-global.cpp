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
    bool f = true;
    int check(TreeNode *root){
        if(root==NULL) return 0;

        int left = check(root->right);
        int right = check(root->left);
        if(abs(left-right)>1){
            // cout<<root->val<<": "<<left<<" "<<right<<endl;
            f = false;
        } 
        return max(left,right)+1;
    }

    int check2(TreeNode *root){
        if(root==NULL) return 0;
        int left = check2(root->left);

        if(left==-1) return -1;

        int right = check2(root->right);

        if(right==-1) return -1;

        if(abs(left-right)>1) return -1;

        return max(left,right)+1;
    }

    bool isBalanced(TreeNode* root) {

        // check(root);
        // return f;

        // without global variables
        return check2(root) != -1;
    }
};