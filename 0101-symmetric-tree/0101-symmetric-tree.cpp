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
    bool isSymmetric(TreeNode* root) {    
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

            q.push(leftNode->left);
            q.push(leftNode->right);
            p.push(rightNode->right);            
            p.push(rightNode->left);
        }
        
        return q.empty() && p.empty();
        
    }
};