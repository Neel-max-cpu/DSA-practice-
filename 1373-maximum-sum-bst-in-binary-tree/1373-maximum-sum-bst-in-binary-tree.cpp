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


class Neel {
    public:
    int maxNode, minNode, sum;
    Neel (int minNode, int maxNode, int sum){
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->sum = sum;
    }
};

class Solution {
public:
    int ans = 0;

    int findSum(TreeNode *root){
        if(!root) return 0;
        int val = root->val;
        int left=findSum(root->left);
        int right = findSum(root->right);
        return val+left+right;
    }

    bool isValid(TreeNode*root, int mini, int maxi){
        if(!root) return true;

        return (
            (root->val > mini) && 
            (root->val < maxi) &&
            isValid(root->left, mini, root->val) &&
            isValid(root->right, root->val, maxi)
        );
    }

    pair<int,bool> betterIsValid(TreeNode*root, int mini, int maxi){
        if(!root) return {0,true};

        pair<int,bool>one, two, three, four;
        if(root->val < mini) one = {root->val, false};
        else one = {root->val, true};

        if(root->val > maxi) two = {root->val, false};
        else two = {root->val, true};

        three = betterIsValid(root->left, mini, root->val);
        four = betterIsValid(root->right, root->val, maxi);

        if(one.second==true && two.second==true && three.second==true && four.second==true){
            int val = root->val + three.first + four.first;
            return {val, true};
        }
        else{
            return {-1, false};
        }        
    }

    void check(TreeNode*root){
        if(!root){
            return;
        }

        // brute ---
        /*
        if(isValid(root, INT_MIN, INT_MAX)){
            int val = findSum(root);
            ans = max(val, ans);            
        } 
        */

        // better ---
        auto a = betterIsValid(root, INT_MIN, INT_MAX);
        if(a.second){    
            ans = max(a.first, ans);            
        } 

        check(root->left);
        check(root->right);        
    }   


    Neel helper(TreeNode*root){
        if(!root){
            // valid so minNode would be max and maxNode would be min
            return Neel(INT_MAX, INT_MIN, 0);
        }

        auto left = helper(root->left);
        auto right = helper(root->right);

        if(left.maxNode < root->val && root->val < right.minNode){
            int sum = left.sum + right.sum + root->val;
            ans = max(ans, sum);
            return Neel(
                min(root->val, left.minNode),
                max(root->val, right.maxNode),
                sum
            );
        }
        // not valid -- then put minNode as min and maxNode as max 
        return Neel(INT_MIN, INT_MAX, max({left.sum, right.sum}));
    }      



    int maxSumBST(TreeNode* root) {
        // brute --- tle
        /*
        if(!root) return 0;
        check(root);       
        return ans; 
        */

        // better --- tle
        /*
        if(!root) return 0;
        check(root);       
        return ans; 
        */

        // optimal ---
        // do geek for geeks to understand -- post order traversal
        helper(root);
        return ans;
    }
};