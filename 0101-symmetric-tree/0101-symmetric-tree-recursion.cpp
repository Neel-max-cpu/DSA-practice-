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

    bool helper(TreeNode *leftNode, TreeNode *rightNode){
        if(leftNode==NULL || rightNode==NULL){
            // both should be null else return false
            return leftNode==rightNode;
        }

        // left should be equal to right 
        return ((leftNode->val==rightNode->val) && helper(leftNode->left, rightNode->right) && helper(leftNode->right, rightNode->left));
    }

    bool isSymmetric(TreeNode* root) {    

        // iterative --
        /*
        if(root==NULL) return false;
        queue<TreeNode*>q;
        queue<TreeNode*>p;            

        q.push(root->left);
        p.push(root->right); 

        while(!q.empty() && !p.empty()){
            TreeNode *leftNode = q.front();
            q.pop();
            TreeNode *rightNode = p.front();
            p.pop();

            if(leftNode==NULL && rightNode==NULL) continue;
            if(leftNode==NULL || rightNode==NULL) return false;
            if(leftNode->val != rightNode->val) return false;

            // left should be equal to right
            q.push(leftNode->left);
            p.push(rightNode->right);            

            q.push(leftNode->right);
            p.push(rightNode->left);
        }
        
        return q.empty() && p.empty();
        */

        // recursive --
        if(root == NULL) return true;
        return helper(root->left, root->right);
        
    }
};