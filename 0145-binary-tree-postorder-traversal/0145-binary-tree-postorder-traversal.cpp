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
    vector<int> postorderTraversal(TreeNode* root) {
        // Write your code here.

        // preorder -- root, left, right
        // inorder -- left, root, right
        // postorder -- left, right, root

        stack<pair<TreeNode*, int>>st;
        // tree and state - 1(pre), 2(in), 3(post)
        if(root){
            st.push({root, 1});
        }

        // vector<vector<int>>ans(3);
        // at 0 inorder , 1 pre, and 2 post
        vector<int>ans;

        while(!st.empty()){        
            auto a = st.top();        
            st.pop();

            TreeNode *curr = a.first;
            int state = a.second;
        

            if(state==1){
                // update the state(to 2) and push again
                st.push({curr, state+1});
                // and push the left child if present with state 1
                if(curr->left){                                            
                    st.push({curr->left, 1});
                }        

                // preorder
                // ans[1].push_back(curr->data);
            }

            if(state==2){
                // update the state(to 3) and push again
                st.push({curr, state+1});
                // and push the right child if present with state 1
                if(curr->right){
                    st.push({curr->right, 1});
                }

                // inorder
                // ans[0].push_back(curr->data);
            }

            if(state==3){
                // final pop done
                // post order
                // ans[2].push_back(curr->data);
                ans.push_back(curr->val);
            }        
        }
        return ans;    
    }
};