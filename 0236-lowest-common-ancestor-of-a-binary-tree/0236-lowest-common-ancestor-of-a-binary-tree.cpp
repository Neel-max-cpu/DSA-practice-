/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool helper(TreeNode *root, TreeNode *key){
        if(root==NULL) return false;

        if(root==key) return true;

        bool left = helper(root->left, key);
        bool right = helper(root->right, key);

        return left || right;
    }

    bool getNodes(TreeNode *root, TreeNode *key, vector<TreeNode *>&v, vector<TreeNode *>&temp){
        if(root==NULL) return false;

        temp.push_back(root);
        if(root==key){
            v = temp;
            return true;
        }

        bool left = getNodes(root->left, key, v, temp);
        if(left){            
            return true;
        }        
        bool right = getNodes(root->right, key, v, temp);
        if(right){            
            return true;
        }

        temp.pop_back();
        return false;
    }

    TreeNode * optimal(TreeNode*root, TreeNode* p, TreeNode *q){
        if(root==NULL) return NULL;

        // if we find any one of the nodes return it
        if(root==p || root==q) return root;

        TreeNode *left = optimal(root->left, p, q);
        TreeNode *right = optimal(root->right, p, q);

        // if both sides return not null current is lca
        if(left && right) return root;
        else{
            // return the opposites if one of them is null
            if(left==NULL) return right;
            else return left;   
        }
        
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        // n - height of the tree
        //brute -- helper(n) + 4*called helper(n) [lowestCommonAncestor called worst case N]
        // so tc - o(n2) and sc o(n) = worst case n = height of a skewed tree
        /*
        // lca will be this ---
        if(root==p || root==q) return root;

        TreeNode *ans = NULL;
        // find p in left
        bool leftP = helper(root->left, p);
        // find p in right
        bool rightP = helper(root->right, p);


        // find q in left
        bool leftQ = helper(root->left, q);
        // find q in right
        bool rightQ = helper(root->right, q);

        // if both in left
        if(leftP && leftQ)
            return lowestCommonAncestor(root->left, p, q);

        // if both in right
        else if(rightP && rightQ)
            return lowestCommonAncestor(root->right, p, q);

        // if both in opposites
        else if((leftP && rightQ) || (rightP && leftQ))
            return root;
        
        // dummy
        else return root;
        */

        // better --- getNodes(n) + 2*called getNodes[2*o(n)] space o(n) + min(len of p,q = H) o(h)
        // = o(n) + 2*o(n) + o(h) = o(n)
        // and space forp,q o(n)+o(n) [worst case height = n] and recursion stack space (h) sc = o(n)
        /*
        vector<TreeNode*>forP;
        vector<TreeNode*>forQ;
        vector<TreeNode*>temp1;
        vector<TreeNode*>temp2;
        getNodes(root, p, forP, temp1);
        getNodes(root, q, forQ, temp2);
        
        TreeNode *ans = NULL;
        for(int i=0; i<min(forP.size(), forQ.size()); i++){
            if(forP[i]==forQ[i]) ans = forP[i];
            else {
                break;
            }
        }
        return ans;
        */

        // optimal --- tc - o(n)
        return optimal(root, p, q);
    }
};