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
        if(root==NULL){
            return;
        }
        helper(root->left, ans);        
        ans.push_back(root->val);
        helper(root->right,ans);
    }

    vector<int> inorderTraversal(TreeNode* root) {    
        // inorder - left root right
        vector<int>ans;
        
        // recursively ----
        // helper(root, ans);

        // iteratively --
        /*
        stack<TreeNode*>s;
        TreeNode *current = root;
        while(current != NULL || !s.empty()){
            while(current!=NULL){
                s.push(current);
                current=current->left;
            }
            current = s.top();
            s.pop();
            ans.push_back(current->val);
            current=current->right;
        }                        
        return ans;
        */

        // using morris traversal ---
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
                    current = current->left;
                }
                // else remove the thread
                else{
                    // cut the thread
                    previous->right = NULL;
                    ans.push_back(current->val);
                    current = current->right;
                }                
            }
        } 
        return ans;
    }
};