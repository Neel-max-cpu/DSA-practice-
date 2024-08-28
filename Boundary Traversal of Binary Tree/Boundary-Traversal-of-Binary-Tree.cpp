/************************************************************

    Following is the Binary Tree node structure:

    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode()
        {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
#include <vector>
#include <stack>
using namespace std;

bool isLeaf(TreeNode<int>*root){
    if(root->left==NULL && root->right==NULL) return true;
    else return false;
}

void addleft(TreeNode<int>*root, vector<int>&ans){
    // method 1 --
    // /*
    TreeNode<int>*current = root->left;
    while(current!=NULL){
        // if not leaf node then add
        if(!isLeaf(current)) ans.push_back(current->data);
        if(current->left!=NULL) current=current->left;
        else current = current->right;
    }
    // */

    // method 2 --
    /*
    TreeNode<int>*current = root->left;
    vector<int>temp;
    while(current!=NULL){
        // if not leaf node then add
        if(!isLeaf(current)) temp.push_back(current->data);
        if(current->left!=NULL) current=current->left;
        else current = current->right;
    }

    for(int i=temp.size()-1; i>=0; i--){
        ans.push_back(temp[i]);
    }
    */

}

void addright(TreeNode<int> *root, vector<int> &ans) {
    // method 1 --
    // /*
    TreeNode<int>*current = root->right;
    vector<int>temp;
    while(current!=NULL){
        // if not leaf node then add
        if(!isLeaf(current)) temp.push_back(current->data);
        if(current->right!=NULL) current=current->right;
        else current = current->left;
    }

    for(int i=temp.size()-1; i>=0; i--){
        ans.push_back(temp[i]);
    }       
    // */

    // method 2 --
    /*
    TreeNode<int>*current = root->right;    
    while(current!=NULL){
        // if not leaf node then add
        if(!isLeaf(current)) ans.push_back(current->data);
        if(current->right!=NULL) current=current->right;
        else current = current->left;
    }
    */
}

void addleaf(TreeNode<int>*root, vector<int>&ans){
    // method 1 ---
    // inorder traversal - left, root, right
    // /*
    if(isLeaf(root)){
        ans.push_back(root->data);    
    }
    if(root->left!=NULL) addleaf(root->left, ans);
    if(root->right!=NULL) addleaf(root->right, ans);
    // */

    /*
    // method 2 -- go right then root then left
    if(isLeaf(root)){
        ans.push_back(root->data);        
    }
    if(root->right!=NULL) addleaf(root->right, ans);
    if(root->left!=NULL) addleaf(root->left, ans);
    */
}

vector<int> traverseBoundary(TreeNode<int> *root)
{
	// Write your code here.

    // this is anticolock wise --- method 1
    // /*
    vector<int>ans;
    if(root==NULL) return ans;

    if(!isLeaf(root)) ans.push_back(root->data);

    // left
    addleft(root, ans);
    // add leaf node
    addleaf(root, ans);
    // right
    addright(root, ans);

    return ans;
    // */

    // for clock wise right add first, then leaf node then left(reverse) - method2
    /*
    vector<int>ans;
    if(root==NULL) return ans;

    if(!isLeaf(root)) ans.push_back(root->data);

    // right
    addright(root, ans);
    // add leaf node
    addleaf(root, ans);
    // left
    addleft(root, ans);
    return ans;
    */
}
