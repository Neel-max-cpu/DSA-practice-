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
    void helper(TreeNode *root, vector<int>&ans){
        if(root==NULL) return;
        ans.push_back(root->val);
        helper(root->left, ans);
        helper(root->right, ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        // preorder -- root left right
        vector<int>ans;

        // recursive ---
        // helper(root, ans);

        // iterative ---
        /*
        stack<TreeNode*>s;
        TreeNode*current = root;

        if(root!=NULL) s.push(root);
        while(!s.empty()){
            TreeNode *node = s.top();
            s.pop();
            ans.push_back(node->val);

            // since stack so push the right child first to process the left one first
            if(node->right!=NULL){
                s.push(node->right);
            }
            if(node->left != NULL){
                s.push(node->left);
            }
        }
        return ans;
        */

        // using morris traversal --- similar to inorder just 1 line change
        TreeNode *current = root;
        while(current !=NULL){
            if(current->left==NULL){                
                ans.push_back(current->val);
                current=current->right;
            }
            else{
                /*
                          1
                         / \
                        2   3
                       / \
                      4   5
                           \
                            6
                */
                // left is not null -- take the left subtree's(2s) right most guy(6) and 
                TreeNode *previous = current->left;
                // 2 case if next is null or else current 
                while(previous->right!=NULL && previous->right!=current){
                    previous=previous->right;
                }


                // connect it to current's node(if next is null) after connection is done,                 
                // move to the left permananently
                if(previous->right==NULL){
                    // create the thread
                    previous->right = current; 
                    // push the value when making the thread -- 
                    ans.push_back(current->val);
                    
                    current = current->left;
                }
                // else remove the thread
                else{
                    // cut the thread
                    previous->right = NULL;
                    current = current->right;
                }                
            }
        } 
        return ans;
    }
};