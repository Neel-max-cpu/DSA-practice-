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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        // method 1 --
        /*
        vector<vector<int>>ans;
        if(root==NULL) return ans;

        queue<TreeNode*>q;
        q.push(root);
        int f= 0;

        while(!q.empty()){
            int size = q.size();
            vector<int>temp;
            if(f==0){
                for(int i=0; i<size; i++){
                    TreeNode *current = q.front();
                    q.pop();
                    temp.push_back(current->val);
                    if(current->left!=NULL) q.push(current->left);
                    if(current->right!=NULL) q.push(current->right);
                }
                ans.push_back(temp);
                f =1;
            }
            else {
                for(int i=0; i<size; i++){
                    TreeNode *current = q.front();
                    q.pop();
                    temp.push_back(current->val);
                    if(current->left!=NULL) q.push(current->left);
                    if(current->right!=NULL) q.push(current->right);
                }
                reverse(temp.begin(), temp.end());
                ans.push_back(temp);
                f =0;
            }
        }

        return ans;        
        */
        
        // method 2 --
        vector<vector<int>>ans;
        if(root==NULL) return ans;

        queue<TreeNode*>q;
        q.push(root);
        int f= 0;
        while(!q.empty()){
            int size = q.size();
            vector<int>temp(size);
            if(f==0){
                for(int i=0; i<size; i++){
                    TreeNode *current = q.front();
                    q.pop();
                    temp[i] = current->val;
                    if(current->left!=NULL) q.push(current->left);
                    if(current->right!=NULL) q.push(current->right);
                }
                ans.push_back(temp);
                f =1;
            }
            else {
                for(int i=0; i<size; i++){
                    TreeNode *current = q.front();
                    q.pop();
                    temp[size-1-i] = current->val;
                    if(current->left!=NULL) q.push(current->left);
                    if(current->right!=NULL) q.push(current->right);
                }                
                ans.push_back(temp);
                f =0;
            }
        }
        return ans;        
    }
};