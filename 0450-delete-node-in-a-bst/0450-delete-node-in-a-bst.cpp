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

    TreeNode *findLastRight(TreeNode *root){
        if(root->right == NULL) return root;
        return findLastRight(root->right);
    }

    TreeNode *helper(TreeNode *root){
        if(root->left == NULL){
            return root->right;
        }
        else if(root->right == NULL) return root->left;

        TreeNode *rightChild = root->right;
        TreeNode *lastRight = findLastRight(root->left);
        lastRight->right = rightChild;
        // making all the right to left
        return root->left;
    }


    TreeNode *findLastLeft(TreeNode *root){
        if(root->left == NULL) return root;
        return findLastLeft(root->left);
    }
    
    TreeNode *helper2(TreeNode *root){
        if(root->left == NULL){
            return root->right;
        }
        else if(root->right == NULL) return root->left;

        TreeNode *leftChild = root->left;
        TreeNode *lastLeft = findLastLeft(root->right);
        lastLeft->right = leftChild;
        // making all the left to right
        return root->right;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        // if both the right and left is not null
        // method 1 --- putting it in the right of the leftchild(biggest number), 
        // method 2 -- putting it in the left of the right child(smallest number)
        if(root==NULL) return NULL;
        if(root->val==key) return helper(root);
        TreeNode *dummy = root;
        while(root!=NULL){
            if(root->val > key){
                if(root->left != NULL && root->left->val==key){
                    // method 1 
                    root->left = helper(root->left);
                    // method 2
                    // root->left = helper2(root->left);
                    break;
                }
                else {
                    root = root->left;
                }
            }
            else{
                if(root->right != NULL && root->right->val==key){
                    // method 1
                    root->right = helper(root->right);
                    // method 2
                    // root->right = helper2(root->right);
                    break;
                }
                else{
                    root = root->right;
                }
            }
        }
        return dummy;
    }
};