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

class NodeValue{
public:
    int minNode, maxNode, sum;

    NodeValue(int minNode, int maxNode, int sum){
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->sum = sum;        
    }
};

class Solution {
public:
    int ans = 0;
    bool isValid(TreeNode*root, long a, long b){
        if(root==NULL) return true;
        bool f1 = isValid(root->left, a, root->val);
        bool f2 = isValid(root->right, root->val, b);

        if((root->val>a && root->val<b) && f1 && f2) return true;
        else return false;
    }

    int find(TreeNode*root){        
        queue<TreeNode*>q;
        q.push(root);
        int ans = 0;
        while(!q.empty()){
            for(int i=0; i<q.size(); i++){
                TreeNode*current = q.front();
                q.pop();            
                ans += current->val;
                if(current->left!=NULL) q.push(current->left);
                if(current->right!=NULL) q.push(current->right);
            }
        }
        return ans;
    }

    NodeValue helper(TreeNode*root){
        if(root==NULL) return NodeValue(INT_MAX, INT_MIN, 0);

        auto left = helper(root->left);
        auto right = helper(root->right);

        // if left's maximum < root's val < right's min then a valid bst
        if(left.maxNode<root->val &&  root->val<right.minNode){
            // min would be min of root, left's minimum
            int minNode = min(root->val, left.minNode);
            // max would be max of root, right maximum
            int maxNode = max(root->val, right.maxNode);
            int sum = left.sum+right.sum+root->val;
            ans = max(sum, ans);            
            return NodeValue(minNode, maxNode, sum);
        }
        // other wise return a very big number -- struct is (min, max, sum) 
        // root's value can't be greater than left's max value(INT_MAX) and root's value can't be samller then rights' min value(INT_MIN)
        return NodeValue(INT_MIN, INT_MAX, max(left.sum, right.sum));
    }

    int maxSumBST(TreeNode* root) {
        if(root==NULL) return 0;
        // brute -- o(n^2)
        /*
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode*current = q.front();
            q.pop();
            if(isValid(current, LLONG_MIN, LLONG_MAX)){
                int sum = find(current);
                cout<<current->val<<" "<<sum<<endl;
                ans = max(ans, sum);
            }
            if(current->left!=NULL) q.push(current->left);
            if(current->right!=NULL) q.push(current->right);
        }
        return ans;
        */

        // optimal -- using post order , left right, node
        
        helper(root);
        return ans;
        
    }
};