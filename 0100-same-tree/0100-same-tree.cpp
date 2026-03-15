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
    bool helper(TreeNode *p, TreeNode*q){
        // check both null
        if(p==NULL && q==NULL) return true;

        // only one is null (cause both null check above)
        if(p==NULL || q==NULL) return false;

        // now both p and q are present -- so check data, move left, move right
        return ((p->val == q->val) && helper(p->left, q->left) && helper(p->right, q->right));
    } 

    bool isSameTree(TreeNode* p, TreeNode* q) {
        // recurisive ---
        // return helper(p, q);

        // iterative --- (recursion better)
        queue<TreeNode*>one;
        queue<TreeNode*>two;

        if(p) one.push(p);
        if(q) two.push(q);

        while(!one.empty() && !two.empty()){
            int len1 = one.size();
            int len2 = two.size();

            if(len1 != len2) {
                cout<<"size not same!"<<endl;
                return false;
            }
            for(int i=0; i<len1; i++){
                TreeNode *x = one.front();
                TreeNode *y = two.front();
                one.pop();
                two.pop();

                // check data
                if(x->val != y->val) return false;

                if(x->left || y->left){
                    // both null no problem
                    if(!x->left && !y->left) continue;
                    else if(!x->left || !y->left){
                        // if one of them is null
                        return false;
                    }
                    else{
                        // both present --
                        one.push(x->left);
                        two.push(y->left);
                    }
                }

                if(x->right || y->right){
                    // both null no problem
                    if(!x->right && !y->right) continue;
                    else if(!x->right || !y->right){
                        // if one of them is null
                        return false;
                    }
                    else{
                        // both present --
                        one.push(x->right);
                        two.push(y->right);
                    }
                }
            }
        }

        if(!one.empty() || !two.empty()) {
            cout<<"one/two is not empty!"<<endl;
            return false;
        }
        else return true;
    }
};