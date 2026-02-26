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
    void preorder(TreeNode*root, vector<int>&ans){
        if(root==NULL) return;

        ans.push_back(root->val);
        preorder(root->left, ans);
        preorder(root->right, ans);
    }

    vector<int>iterative(TreeNode *root){
        stack<TreeNode*>st;
        TreeNode*current = root;
        vector<int>ans;
        while(current || !st.empty()){
            while(current){
                st.push(current);
                ans.push_back(current->val);
                current = current->left;
            }
            current = st.top();
            st.pop();
            current = current->right;
        }
        return ans;
    }

    vector<int>morris(TreeNode*root){
        TreeNode*curr = root;
        vector<int>ans;
        while(curr){
            if(curr->left == NULL){
                // if no left child
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else{                
                // if left child is present then go to the left then the right most 
                // node and connect the root to it
                TreeNode*prev = curr->left;
                while(prev->right && prev->right != curr){
                    prev=prev->right;
                }

                // case 1 right is null then connect a thread
                if(prev->right==NULL){
                    prev->right = curr;
                    // since we mark the thread so its the root and in the end we are printing the root
                    ans.push_back(curr->val);
                    // now we can do the traversal ---
                    curr = curr->left;
                }
                else{
                    // points to curr so disconnect the thread
                    prev->right = NULL;
                    // left is visited so, take curr and then go right                    
                    curr = curr->right;
                }
            }
        }
        return ans;
    }

    vector<int> preorderTraversal(TreeNode* root) {
        // preorder -- root, left, right

        vector<int>ans;
        // recursion
        // preorder(root, ans);

        // iterative --
        // ans = iterative(root);

        // morris --
        ans = morris(root);

        return ans;
                
    }
};